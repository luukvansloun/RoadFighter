//
// Created by luuk on 6-12-18.
//

#include "Game.h"

Game::Game() {
    // Create Game window
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "RoadFighter");

    // Create Factory for creating SFML object entities
    this->sfml_factory = std::make_shared<roadfighterSFML::SFMLFactory>(this->window);
    this->world = std::make_shared<roadfighter::World>();
    world->setPlayercar(sfml_factory->create_playercar());

    // Set Playercar as subject for Game High Score registration
    this->setSubject(world->getPlayercar());

    // Create Opponent Cars
    setup_opponents();

    // Create HighScore object
    this->highscores = std::make_shared<roadfighter::HighScore>();
    highscores->setSubject(world->getPlayercar());

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

void Game::setup_opponents() {
    for(int i = 0; i < 7; i++) {
        this->world->add_opponent(sfml_factory->create_racingcar());
    }

    // Opponent 1 start position
    this->world->getOpponents()[0]->setX(-1.899f);
    this->world->getOpponents()[0]->setY(1.2);


    // Opponent 2 start position
    this->world->getOpponents()[1]->setX(-1.899f);
    this->world->getOpponents()[1]->setY(0.2);

    // Opponent 3 start position
    this->world->getOpponents()[2]->setX(-1.899f);
    this->world->getOpponents()[2]->setY(-0.8f);

    // Opponent 4 start position
    this->world->getOpponents()[3]->setX(-1.899f);
    this->world->getOpponents()[3]->setY(-1.8f);

    // Opponent 5 start position
    this->world->getOpponents()[4]->setX(-0.449f);
    this->world->getOpponents()[4]->setY(1.2);

    // Opponent 6 start position
    this->world->getOpponents()[5]->setX(-0.449f);
    this->world->getOpponents()[5]->setY(0.2);

    // Opponent 7 start position
    this->world->getOpponents()[6]->setX(-0.449f);
    this->world->getOpponents()[6]->setY(-0.8f);

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
    else if(type == "Lorry") {
        auto lorry = this->sfml_factory->create_lorry();

        this->world->add_entity(lorry);
    }
    else if(type == "Bullet") {
        auto bullet = this->sfml_factory->create_bullet();

        bullet->setX(world->getPlayercar()->getX() + (world->getPlayercar()->getWidth() * 0.005f) -
                             (bullet->getWidth() * 0.005f));

        bullet->setY(world->getPlayercar()->getY() + (bullet->getHeight() * 0.005f) + 0.10f);

        this->world->add_entity(bullet);
    }
}

void Game::update() {
    this->score = getSubject()->getScore();
}

void Game::run() {
    unsigned int game_it = 0;
    int opp = 6;
    bool running = false;
    bool start = false;
    std::chrono::steady_clock::time_point start_time;
    bool finish = false;
    auto one = std::chrono::milliseconds(0);
    auto two = std::chrono::milliseconds(750);
    auto three = std::chrono::milliseconds(0);
    auto four = std::chrono::milliseconds(250);

    sf::Font font;
    font.loadFromFile("Pixel-NoirCaps.ttf");

    while(this->window->isOpen()) {
        if(!running) {
            if(start) {
                // Create new world to overwrite the old one
                this->world = std::make_shared<roadfighter::World>();
                world->setPlayercar(sfml_factory->create_playercar());

                // Set new Playercar as subject for Game High Score registration
                this->setSubject(world->getPlayercar());

                // Create new Opponent Cars
                setup_opponents();

                // Create new HighScore object
                this->highscores = std::make_shared<roadfighter::HighScore>();
                highscores->setSubject(world->getPlayercar());

                // Reset variables
                game_it = 0;
                opp = 6;
                running = false;
                start = false;
                finish = false;
            }


            sf::Text road;
            road.setFont(font);
            road.setString("ROAD");
            road.setFillColor(sf::Color::Red);
            road.setOutlineThickness(1);
            road.setOutlineColor(sf::Color::White);
            road.setCharacterSize(50);
            road.setPosition((this->window->getView().getSize().x/2) - (road.getLocalBounds().width / 2), 150);

            sf::Text fighter;
            fighter.setFont(font);
            fighter.setString("FIGHTER");
            fighter.setFillColor(sf::Color::Red);
            fighter.setOutlineThickness(1);
            fighter.setOutlineColor(sf::Color::White);
            fighter.setCharacterSize(50);
            fighter.setPosition((this->window->getView().getSize().x/2) - (fighter.getLocalBounds().width / 2), 225);

            sf::Text start_text;
            start_text.setFont(font);
            start_text.setString("Press Enter To Start");
            start_text.setCharacterSize(16);
            start_text.setPosition((this->window->getView().getSize().x/2) - (start_text.getLocalBounds().width / 2), 425);

            window->draw(road);
            window->draw(fighter);
            window->draw(start_text);

            // Display and clear the screen
            this->window->display();
            this->window->clear(sf::Color::Black);

            sf::Event event;
            while(this->window->pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                    this->window->close();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    running = true;
                    setupBackground();
                    start_time = std::chrono::steady_clock::now();
                }
            }
        }

        else {
            auto now = std::chrono::steady_clock::now();
            auto end = now + std::chrono::milliseconds(16);

            sf::Text counter;
            counter.setFont(font);
            counter.setFillColor(sf::Color::Red);
            counter.setOutlineThickness(1);
            counter.setOutlineColor(sf::Color::White);
            counter.setCharacterSize(60);

            if(std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(1200)) {
                counter.setString("3");
                counter.setPosition((this->window->getView().getSize().x/2) - (counter.getLocalBounds().width / 2),
                                    (this->window->getView().getSize().y/2) - (counter.getLocalBounds().height / 2));
            }
            else if(std::chrono::steady_clock::now() - start_time >= std::chrono::milliseconds(1200) and
                    std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(2200)) {
                counter.setString("2");
                counter.setPosition((this->window->getView().getSize().x/2) - (counter.getLocalBounds().width / 2),
                                    (this->window->getView().getSize().y/2) - (counter.getLocalBounds().height / 2));
            }
            else if(std::chrono::steady_clock::now() - start_time >= std::chrono::milliseconds(2200) and
                    std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(3200)) {
                counter.setString("1");
                counter.setPosition((this->window->getView().getSize().x/2) - (counter.getLocalBounds().width / 2),
                                    (this->window->getView().getSize().y/2) - (counter.getLocalBounds().height / 2));
            }
            else if(std::chrono::steady_clock::now() - start_time >= std::chrono::milliseconds(3200) and
                    std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(3700)) {
                counter.setString("Start!");
                counter.setPosition((this->window->getView().getSize().x/2) - (counter.getLocalBounds().width / 2),
                                    (this->window->getView().getSize().y/2) - (counter.getLocalBounds().height / 2));
            }
            else {
                start = true;
            }

            sf::Event event;

            while(this->window->pollEvent(event)) {
                // Check if window is closed
                if (event.type == sf::Event::Closed) {
                    this->window->close();
                }
            }

            if(start) {
                one += std::chrono::milliseconds(16);
                three += std::chrono::milliseconds(16);

                if(one >= two) {
                    one = std::chrono::milliseconds(0);
                    this->world->getPlayercar()->setFuel(this->world->getPlayercar()->getFuel() - 1);
                    if(this->world->getPlayercar()->getFuel() <= 0) {
                        highscores->write_to_file();
                        running = false;
                        world->getPlayercar()->setSpeed(0);
                    }
                }

                if(game_it < this->game_objects.size()) {
                    // Time frame equals the time the next object should be build
                    int distance_check = this->game_objects[game_it]["distance"];
                    if(distance_check <= world->getPlayercar()->getDistance()) {
                        if(this->game_objects[game_it]["obstacle"].get<std::string>() == "End") {
                            finish = true;
                        }
                        else if(this->game_objects[game_it]["obstacle"].get<std::string>() == "Opponent") {


                            this->world->getOpponents()[opp]->decrease_speed(100);
                            opp -= 1;

                            game_it += 1;
                        }

                        else {
                            if(world->getEntities().size() < 3) {
                                add_entity(this->game_objects[game_it]["obstacle"].get<std::string>());
                            }

                            // Update to next
                            game_it += 1;
                        }
                    }
                }

                // Update distance travelled: 16 milliseconds (per tick) times the speed
                this->world->getPlayercar()->update_distance(0.0044 * this->world->getPlayercar()->getSpeed());

                if(!world->getPlayercar()->isCrashed()) {
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
                        // TODO Move to World
                        if(world->getPlayercar()->getSpeed() < world->getPlayercar()->getMax_speed()) {
                            world->getPlayercar()->setSpeed(world->getPlayercar()->getSpeed() + 2.5);
                        }
                    }
                    // Decrease player speed
                    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        // TODO Move to World
                        if(world->getPlayercar()->getSpeed() > 0) {
                            world->getPlayercar()->setSpeed(world->getPlayercar()->getSpeed() - 7.5);
                        }
                    }
                    // Shoot bullet
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        if(!world->getPlayercar()->isShoot()) {
                            world->getPlayercar()->setShoot(true);
                        }
                        else {
                            if(three >= four) {
                                three = std::chrono::seconds(0);
                                if(world->getPlayercar()->getBullets() > 0) {
                                    add_entity("Bullet");
                                    world->getPlayercar()->setBullets(world->getPlayercar()->getBullets() - 1);
                                    world->getPlayercar()->setShoot(false);
                                }
                            }
                        }
                    }
                }

                // Move Background
                if(!finish) {
                    update_background();
                }
                else {
                    running = end_of_game();
                }

                // Update Entity and Opponent Positions
                world->update_all();
            }

            if(!start) {
                world->start_update();
            }

            // Draw
            this->window->draw(this->background);
            world->draw();

            sf::Text text;
            text.setFont(font);

            std::string text_string = "Your Score: \n\n";
            if(!start) {
                // Showing zero due to possible remembrance of the old score in case of restart
                text_string += "0";
            }
            else {
                text_string += std::to_string((int)round(score));
            }
            text_string +=  "\n\n";

            text_string += "High Scores: \n\n";
            std::vector<double> temp_scores = highscores->getHighscores();
            std::sort(temp_scores.begin(), temp_scores.end());

            text_string += "1.    " + std::to_string((int)round(temp_scores[9])) + "\n";
            text_string += "2.    " + std::to_string((int)round(temp_scores[8])) + "\n";
            text_string += "3.    " + std::to_string((int)round(temp_scores[7])) + "\n";
            text_string += "4.    " + std::to_string((int)round(temp_scores[6])) + "\n";
            text_string += "5.    " + std::to_string((int)round(temp_scores[5])) + "\n";
            text_string += "6.    " + std::to_string((int)round(temp_scores[4])) + "\n";
            text_string += "7.    " + std::to_string((int)round(temp_scores[3])) + "\n";
            text_string += "8.    " + std::to_string((int)round(temp_scores[2])) + "\n";
            text_string += "9.    " + std::to_string((int)round(temp_scores[1])) + "\n";
            text_string += "10.   " + std::to_string((int)round(temp_scores[0])) + "\n\n\n";

            text_string += "Speed: ";
            text_string += std::to_string(int(this->world->getPlayercar()->getSpeed())) + "km/h"  + "\n\n\n\n";

            text_string += "Fuel: ";
            text_string += std::to_string(this->world->getPlayercar()->getFuel())  + "\n\n\n\n";

            text_string += "Bullets: ";
            text_string += std::to_string(this->world->getPlayercar()->getBullets());

            text.setString(text_string);

            text.setCharacterSize(11);
            text.setPosition(600, 50);

            window->draw(text);

            if(!start) {
                window->draw(counter);
            }

            // Display and clear the screen
            this->window->display();
            this->window->clear(sf::Color::Black);

            // Wait until the next frame is due
            std::this_thread::sleep_until(end);

            // Game has ended due to finishing or fuel levels being zero
            // TODO FIX ENDING SCREEN
        }
    }
}

bool Game::end_of_game() {
    if(!this->EOG) {
        this->background.setPosition(0, this->background.getPosition().y +
                                        float(world->getPlayercar()->getSpeed() * 0.075));
        if(this->background.getPosition().y >= -20) {
            finish_background();
            this->EOG = true;
        }

        return true;
    }
    else {
        if(this->world->move_player_up()){
            highscores->write_to_file();
            return false;
        }
        else {
            this->world->getPlayercar()->change_position();
            return true;
        }
    }
}














