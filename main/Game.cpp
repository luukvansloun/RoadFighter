//
// Created by luuk on 6-12-18.
//

#include "Game.h"

Game::Game() {
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "RoadFighter");

    this->sfml_factory = std::make_shared<roadfighterSFML::SFMLFactory>(this->window);

    this->world = std::make_shared<roadfighterSFML::WorldSFML>();

    world->setPlayercar(sfml_factory->create_playercar());
}

Game::~Game() {}

void Game::run() {
    while(this->window->isOpen()) {

        sf::Event event;

        while(this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }

        }
        this->window->clear(sf::Color::Black);



        this->window->display();
    }
}
