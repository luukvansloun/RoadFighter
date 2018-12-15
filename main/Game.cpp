//
// Created by luuk on 6-12-18.
//

#include "Game.h"

Game::Game() {
    // Create Game window
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "RoadFighter");

//    window->setKeyRepeatEnabled(false);

    // Create Factory for creating SFML object entities
    this->sfml_factory = std::make_shared<roadfighterSFML::SFMLFactory>(this->window);
    this->world = std::make_shared<roadfighter::World>();
    world->setPlayercar(sfml_factory->create_playercar());

    // Create Opponent Cars
    setup_opponents();

    // Read game from JSON file
    std::ifstream input("test.json");

    if(!input.is_open()) {
        std::cout << "Couldn't open game json" << std::endl;
        exit(0);
    }
    else {
        // Create json object
        nlohmann::json j;
        input >> j;

        // Add all game elements to object vector
        for(const auto& x : j["Elements"]) {
            game_objects.push_back(x);
        }

        input.close();
    }
}

Game::~Game() {}

void Game::setup_opponents() {
    for(int i = 0; i < 7; i++) {
        this->world->add_opponent(sfml_factory->create_racingcar());
    }

    // Opponent 1 start position
    this->world->getOpponents()[0]->setX(-1.899);
    this->world->getOpponents()[0]->setY(1.2);


    // Opponent 2 start position
    this->world->getOpponents()[1]->setX(-1.899);
    this->world->getOpponents()[1]->setY(0.2);

    // Opponent 3 start position
    this->world->getOpponents()[2]->setX(-1.899);
    this->world->getOpponents()[2]->setY(-0.8);

    // Opponent 4 start position
    this->world->getOpponents()[3]->setX(-1.899);
    this->world->getOpponents()[3]->setY(-1.8);

    // Opponent 5 start position
    this->world->getOpponents()[4]->setX(-0.449);
    this->world->getOpponents()[4]->setY(1.2);

    // Opponent 6 start position
    this->world->getOpponents()[5]->setX(-0.449);
    this->world->getOpponents()[5]->setY(0.2);

    // Opponent 7 start position
    this->world->getOpponents()[6]->setX(-0.449);
    this->world->getOpponents()[6]->setY(-0.8);

    // Change positions of all
    for(const auto& opponent : this->world->getOpponents()) {
        opponent->change_position();
    }
}

void Game::setupBackground() {

    if(!this->bgTexture.loadFromFile("./sprites/BG2.png")) {
        std::cout << "Could not load background image" << std::endl;
    }

    this->background.setTexture(bgTexture);

    auto bg_co = Transformation::get_instance().get_coordinates(std::make_pair(-4, 5), this->window->getView().getSize().x,
                                                                this->window->getView().getSize().y);

    this->background.setPosition(bg_co.first, bg_co.second);

    this->view.reset(sf::FloatRect(0, 0, this->window->getView().getSize().x, this->window->getView().getSize().y));
    this->view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
}

void Game::update_background() {
    if(world->getPlayercar()->getSpeed() > 0) {
        this->background.setPosition(0, this->background.getPosition().y +
                                        float(world->getPlayercar()->getSpeed() * 0.075));

        if(background.getPosition().y >= 0) {
            background.setPosition(0, -200);
        }
    }
}

void Game::finish_background() {
    this->bgTexture.loadFromFile("sprites/BG_Finish.png");
    this->background.setTexture(bgTexture);
}

void Game::add_entity(std::string type) {
    if(type == "Truck") {
        auto truck = this->sfml_factory->create_truck();

        this->world->add_entity(truck);
    }
    if(type == "Lorry") {
        auto lorry = this->sfml_factory->create_lorry();

        this->world->add_entity(lorry);
    }
}

void Game::run() {
    setupBackground();
    int game_it = 0;
    int opp = 0;
    int speed_decrease = 160;
    bool finish = false;
    auto one = std::chrono::milliseconds(0);
    auto two = std::chrono::milliseconds(750);

    while(this->window->isOpen()) {
        auto now = std::chrono::steady_clock::now();
        auto end = now + std::chrono::milliseconds(16);

        one = one + std::chrono::milliseconds(16);

        if(one >= two) {
            one = std::chrono::milliseconds(0);
            this->world->getPlayercar()->setFuel(this->world->getPlayercar()->getFuel() - 1);
            std::cout << this->world->getPlayercar()->getFuel() << std::endl;
            if(this->world->getPlayercar()->getFuel() <= 0) {
                std::cout << "Out of fuel" << std::endl;
                exit(0);
            }
        }

        sf::Event event;

        if(game_it < this->game_objects.size()) {
            // Time frame equals the time the next object should be build
            int distance_check = this->game_objects[game_it]["distance"];
            if(distance_check <= world->getPlayercar()->getDistance()) {
                if(this->game_objects[game_it]["obstacle"].get<std::string>() == "End") {
                    finish = true;
                }
                else if(this->game_objects[game_it]["obstacle"].get<std::string>() == "Opponent") {
                    this->world->getOpponents()[opp]->decrease_speed(speed_decrease);

                    speed_decrease -= 20;
                    opp += 1;

                    game_it += 1;
                }

                else {
                    add_entity(this->game_objects[game_it]["obstacle"].get<std::string>());

                    // Update to next
                    game_it += 1;
                }
            }
        }

        // Update distance travelled: 16 milliseconds (per tick) times the speed
        this->world->getPlayercar()->update_distance(0.0044 * this->world->getPlayercar()->getSpeed());

        while(this->window->pollEvent(event)) {
            // Check if window is closed
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
        }

        // Move player to the right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            world->move_player_right();
        }
        // Move player to the left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            world->move_player_left();
        }
        // Increase player speed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(world->getPlayercar()->getSpeed() < world->getPlayercar()->getMax_speed()) {
                world->getPlayercar()->setSpeed(world->getPlayercar()->getSpeed() + 2.5);
            }
        }
        // Decrease player speed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(world->getPlayercar()->getSpeed() > 0) {
                world->getPlayercar()->setSpeed(world->getPlayercar()->getSpeed() - 5);
            }
        }

        // Move Background
        if(!finish) {
            update_background();
        }
        else {
            end_of_game();
        }

        // Update Entity and Opponent Positions
        world->update_entities();
        world->update_opponents();

        // Draw
        this->window->draw(this->background);
        world->draw();

        // TEMP FUEL CHECK

        sf::Text text;
        sf::Font font;
        font.loadFromFile("Pixel-NoirCaps.ttf");
        text.setFont(font);

        std::string text_string = "Speed: ";
        text_string += std::to_string(int(this->world->getPlayercar()->getSpeed())) + "km/h"  + "\n\n\n\n";

        text_string += "Fuel: ";
        text_string += std::to_string(this->world->getPlayercar()->getFuel());

        text.setString(text_string);

        text.setCharacterSize(15);
        text.setPosition(575, 200);

        window->draw(text);

        // TEMP FUEL CHECK



        // Display and clear the screen
        this->window->display();
        this->window->clear(sf::Color::Black);

        // Wait until the next frame is due
        std::this_thread::sleep_until(end);
    }
}

void Game::end_of_game() {
    if(!this->EOG) {

        this->background.setPosition(0, this->background.getPosition().y +
                                        float(world->getPlayercar()->getSpeed() * 0.075));
        if(this->background.getPosition().y >= -20) {
            finish_background();
            this->EOG = true;
        }
    }
    else {
        if(this->world->move_player_up()){
            exit(0);
        }
        else {
            this->world->getPlayercar()->change_position();
        }
    }
}












