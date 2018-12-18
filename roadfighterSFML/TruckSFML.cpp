//
// Created by luuk on 10-12-18.
//

#include "TruckSFML.h"

roadfighterSFML::TruckSFML::TruckSFML(std::shared_ptr<sf::RenderWindow> window) {
    // Set Window
    this->window = window;

    // Random generated X coordinate
    float rand_x = Random::get_instance().get_random_x();
    setX(rand_x);

    // Normal top starting Y coordinate
    setY(float(5));

    // Setup Sprite
    sprite.setSize(sf::Vector2f(56.0f, 81.0f));

    texture.loadFromFile("./sprites/truck.png");

    sprite.setTexture(&texture);

    // Scale down to 80% of the original image size
    sprite.setScale(0.8f, 0.8f);

    // Setup explosion
    this->explosion = std::make_shared<roadfighterSFML::Explosion>();

    // Set width and height for later collision detection
    this->width = sprite.getGlobalBounds().width;
    this->height = sprite.getGlobalBounds().height;

    auto co = Transformation::get_instance().get_coordinates(std::make_pair(rand_x, 5),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::TruckSFML::change_position() {
    auto co = Transformation::get_instance().get_coordinates(std::make_pair(this->getX(), this->getY()),
                                                             this->window->getView().getSize().x,
                                                             this->window->getView().getSize().y);

    this->sprite.setPosition(co.first, co.second);
}

void roadfighterSFML::TruckSFML::draw() {
    this->window->draw(this->sprite);
}

float roadfighterSFML::TruckSFML::getWidth() const {
    return width;
}

float roadfighterSFML::TruckSFML::getHeight() const {
    return height;
}

void roadfighterSFML::TruckSFML::update(bool crashed) {
    if(crashed) {
        this->explosion->Update();
    }
    this->sprite.setTextureRect(explosion->texture_rect);
}

bool roadfighterSFML::TruckSFML::explosion_finished() {
    return explosion->finished;
}

