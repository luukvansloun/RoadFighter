//
// Created by luuk on 10-12-18.
//

#include "LorrySFML.h"

roadfighterSFML::LorrySFML::LorrySFML(std::shared_ptr<sf::RenderWindow> window) {
    // Set Window
    this->window = window;

    // Random generated X coordinate
    float rand_x = Random::get_instance().get_random_x();
    setX(rand_x);

    // Normal top starting Y coordinate
    setY(float(5));

    // Setup Sprite
    texture.loadFromFile("./sprites/lorry.png");

    sprite.setTexture(texture);

    // Scale down to 80% of the original image size
    sprite.setScale(0.8f, 0.8f);

    // Set width and height for later collision detection
    this->width = sprite.getGlobalBounds().width;
    this->height = sprite.getGlobalBounds().height;

    auto co = Transformation::get_instance().get_coordinates(std::make_pair(rand_x, 5),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::LorrySFML::change_position() {
    auto co = Transformation::get_instance().get_coordinates(std::make_pair(this->getX(), this->getY()),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::LorrySFML::draw() {
    this->window->draw(this->sprite);
}

float roadfighterSFML::LorrySFML::getWidth() const {
    return width;
}

float roadfighterSFML::LorrySFML::getHeight() const {
    return height;
}

