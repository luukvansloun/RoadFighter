//
// Created by luuk on 5-12-18.
//

#include "RacingCarSFML.h"

// RACINGCAR SFML CLASS

roadfighterSFML::RacingCarSFML::RacingCarSFML(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;

    // Setup Sprite
    sprite.setSize(sf::Vector2f(56.0f, 81.0f));

    texture.loadFromFile("./sprites/opponent.png");

    sprite.setTexture(&texture);

    // Scale down to 80% of the original image size
    sprite.setScale(0.8f, 0.8f);

    // Setup explosion
    this->explosion = std::make_shared<roadfighterSFML::Explosion>();

    // Set width and height for later collision detection
    this->width = sprite.getGlobalBounds().width;
    this->height = sprite.getGlobalBounds().height;
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

float roadfighterSFML::RacingCarSFML::getWidth() const {
    return width;
}

float roadfighterSFML::RacingCarSFML::getHeight() const {
    return height;
}

void roadfighterSFML::RacingCarSFML::update(bool crashed) {
    if(crashed) {
        this->explosion->Update();
    }
    this->sprite.setTextureRect(explosion->texture_rect);
}

bool roadfighterSFML::RacingCarSFML::explosion_finished() {
    return explosion->finished;
}
