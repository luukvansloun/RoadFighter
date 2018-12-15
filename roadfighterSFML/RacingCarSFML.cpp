//
// Created by luuk on 5-12-18.
//

#include "RacingCarSFML.h"

// RACINGCAR SFML CLASS

roadfighterSFML::RacingCarSFML::RacingCarSFML(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;

    // Setup Sprite
    texture.loadFromFile("./sprites/racingcar.png");

    sprite.setTexture(texture);

    // Scale down to 80% of the original image size
    sprite.setScale(0.8f, 0.8f);
}

void roadfighterSFML::RacingCarSFML::change_position() {
    auto co = Transformation::get_instance().get_coordinates(std::make_pair(this->getX(), this->getY()),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::RacingCarSFML::draw() {
    this->window->draw(this->sprite);
}

roadfighterSFML::RacingCarSFML::~RacingCarSFML() {}