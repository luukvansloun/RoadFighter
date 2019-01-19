//
// Created by luuk on 5-12-18.
//

#include "PlayerCarSFML.h"

// PLAYERCAR SFML CLASS

roadfighterSFML::PlayerCarSFML::PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window) {
    // Set Window
    this->window = window;

    // Set Coördinates
    this->setX(float(-0.449));
    this->setY(float(-1.8));

    // Setup Sprite
    sprite.setSize(sf::Vector2f(56.0f, 81.0f));

    texture.loadFromFile("./sprites/player.png");

    sprite.setTexture(&texture);

    // Scale down to 80% of the original image size
    sprite.setScale(0.8f, 0.8f);

    // Setup explosion
    this->explosion = std::make_shared<roadfighterSFML::Explosion>();

    // Set width and height for later collision detection
    this->width = sprite.getGlobalBounds().width;
    this->height = sprite.getGlobalBounds().height;

    auto co = Transformation::get_instance().get_coordinates(std::make_pair(-0.449, -1.8),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::PlayerCarSFML::change_position() {
    auto co = Transformation::get_instance().get_coordinates(std::make_pair(this->getX(), this->getY()),
                                                                this->window->getView().getSize().x,
                                                                this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::PlayerCarSFML::draw() {
    this->window->draw(this->sprite);
}

float roadfighterSFML::PlayerCarSFML::getWidth() const {
    return width;
}

float roadfighterSFML::PlayerCarSFML::getHeight() const {
    return height;
}

void roadfighterSFML::PlayerCarSFML::update(bool crashed) {
    if(crashed) {
        this->explosion->Update();
        if(this->explosion->finished) {
            this->setCrashed(false);
            this->explosion->finished = false;
        }
    }
    this->sprite.setTextureRect(explosion->texture_rect);
}



