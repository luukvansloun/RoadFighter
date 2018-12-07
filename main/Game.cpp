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

void Game::setupBackground() {

    if(!this->bgTexture.loadFromFile("./sprites/BG.png")) {
        std::cout << "Could not load background image" << std::endl;
    }

    this->background.setTexture(bgTexture);

    auto bg_co = Transformation::getInstance()->get_coordinates(std::make_pair(-4, 5), this->window->getView().getSize().x,
                                                                this->window->getView().getSize().y);

    this->background.setPosition(bg_co.first, bg_co.second);

    this->view.reset(sf::FloatRect(0, 0, this->window->getView().getSize().x, this->window->getView().getSize().y));
    this->view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
}

Game::~Game() {}

void Game::run() {
    setupBackground();

    while(this->window->isOpen()) {

        sf::Event event;

        while(this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
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
                    world->getPlayercar()->setSpeed(world->getPlayercar()->getSpeed() - 15);
                }
            }
        }

        if(world->getPlayercar()->getSpeed() > 0) {
            this->background.setPosition(0,
                    this->background.getPosition().y + float(world->getPlayercar()->getSpeed() * 0.01));
            if(background.getPosition().y >= 0) {
                background.setPosition(0, -200);
            }
        }

        this->window->draw(this->background);
        world->getPlayercar()->draw();

        this->window->display();
        this->window->clear(sf::Color::Black);
    }
}


