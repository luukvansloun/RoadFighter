//
// Created by luuk on 6-12-18.
//

#include "Game.h"

Game::Game() {
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "RoadFighter");

    this->sfml_factory = std::make_shared<roadfighterSFML::SFMLFactory>(this->window);

    this->world = std::make_shared<roadfighter::World>();

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                world->move_player_right();
                world->getPlayercar()->change_position();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                world->move_player_left();
                world->getPlayercar()->change_position();
            }
        }

        this->window->clear(sf::Color::Black);

        world->getPlayercar()->draw();

        this->window->display();
    }
}
