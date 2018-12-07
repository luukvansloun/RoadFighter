//
// Created by luuk on 5-12-18.
//

#include "PlayerCarSFML.h"

// PLAYERCAR SFML CLASS

roadfighterSFML::PlayerCarSFML::PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window) {
    // Set Window
    this->window = window;

    // Set Coördinates
    this->setX(float(-0.50));
    this->setY(float(-1.8));

    // Setup Sprite
    texture.loadFromFile("./sprites/player_sprite.png");

    sprite.setTexture(texture);

    // TEMP: PhotoShop to correct size
    sprite.setScale(0.2f, 0.2f);

    auto co = Transformation::getInstance()->get_coordinates(std::make_pair(-0.50, -1.8),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::PlayerCarSFML::change_position() {
    auto co = Transformation::getInstance()->get_coordinates(std::make_pair(this->getX(), this->getY()),
                                                                this->window->getView().getSize().x,
                                                                this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

roadfighterSFML::PlayerCarSFML::~PlayerCarSFML() {}

void roadfighterSFML::PlayerCarSFML::draw() {
    this->window->draw(this->sprite);
}




