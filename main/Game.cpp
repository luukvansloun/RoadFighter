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

    // Read game from JSON file
    std::ifstream input("game.json");

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

void Game::setupBackground() {

    if(!this->bgTexture.loadFromFile("./sprites/BG2.png")) {
        std::cout << "Could not load background image" << std::endl;
    }

    this->background.setTexture(bgTexture);

    auto bg_co = Transformation::getInstance()->get_coordinates(std::make_pair(-4, 5), this->window->getView().getSize().x,
                                                                this->window->getView().getSize().y);

    this->background.setPosition(bg_co.first, bg_co.second);

    this->view.reset(sf::FloatRect(0, 0, this->window->getView().getSize().x, this->window->getView().getSize().y));
    this->view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
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

    while(this->window->isOpen()) {
        auto now = std::chrono::steady_clock::now();
        auto end = now + std::chrono::milliseconds(16);

        sf::Event event;

//        if(game_it != (this->game_objects.size() - 1)) {
//            // Time frame equals the time the next object should be build
//            if(this->game_objects[game_it]["distance"] == world->getPlayercar()->getDistance()) {
//
//                add_entity(this->game_objects[game_it]["obstacle"]);
//
//                // Update to next
//                game_it += 1;
//            }
//        }

        while(this->window->pollEvent(event)) {
            // Check if window is closed
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
        }

        // Move player to the right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            world->move_player_right();
            world->getPlayercar()->change_position();
        }
        // Move player to the left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            world->move_player_left();
            world->getPlayercar()->change_position();
        }
        // Increase player speed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(world->getPlayercar()->getSpeed() < world->getPlayercar()->getMax_speed()) {
                world->getPlayercar()->setSpeed(world->getPlayercar()->getSpeed() + 10);
            }
        }
        // Decrease player speed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(world->getPlayercar()->getSpeed() > 0) {
                world->getPlayercar()->setSpeed(world->getPlayercar()->getSpeed() - 10);
            }
        }

        // Move Background
        if(world->getPlayercar()->getSpeed() > 0) {
            this->background.setPosition(0,
                    this->background.getPosition().y + float(world->getPlayercar()->getSpeed() * 0.075));
            if(background.getPosition().y >= 0) {
                background.setPosition(0, -200);
            }
        }

        // Update Entities ///////////






        //////////////////////////////

        // Draw
        this->window->draw(this->background);
        world->getPlayercar()->draw();

        for(const auto& entity : world->getEntities()) {
            entity->draw();
        }

        // Display and clear the screen
        this->window->display();
        this->window->clear(sf::Color::Black);

        // Wait until the next frame is due
        std::this_thread::sleep_until(end);
    }
}




