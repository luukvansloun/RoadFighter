//
// Created by luuk on 19-12-18.
//

#include "BulletSFML.h"

roadfighterSFML::BulletSFML::BulletSFML(std::shared_ptr<sf::RenderWindow> window) {
    // Set Window
    this->window = window;

    // Setup Sprite
    sprite.setSize(sf::Vector2f(8.0f, 17.0f));

    texture.loadFromFile("./sprites/bullet.png");

    sprite.setTexture(&texture);

    // Set width and height for later collision detection
    this->width = sprite.getGlobalBounds().width;
    this->height = sprite.getGlobalBounds().height;
}

void roadfighterSFML::BulletSFML::change_position() {
    auto co = Transformation::get_instance().get_coordinates(std::make_pair(this->getX(), this->getY()),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::BulletSFML::draw() {
    this->window->draw(this->sprite);
}

float roadfighterSFML::BulletSFML::getWidth() const {
    return width;
}

float roadfighterSFML::BulletSFML::getHeight() const {
    return height;
}

