//
// Created by luuk on 5-12-18.
//

#include "PlayerCarSFML.h"

// PLAYERCAR SFML CLASS

roadfighterSFML::PlayerCarSFML::PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

roadfighterSFML::PlayerCarSFML::~PlayerCarSFML() {}

void roadfighterSFML::PlayerCarSFML::setup_sfml(std::string path_to_sprite, float x, float y) {
    if(!texture.loadFromFile(path_to_sprite)) {
        std::cout << "Faaack" << std::endl;
    }
    sprite.setTexture(texture);

    sprite.setPosition(x, y);

    sprite.setScale(0.2f, 0.2f);
}

const sf::Sprite &roadfighterSFML::PlayerCarSFML::getSprite() const {
    return sprite;
}

void roadfighterSFML::PlayerCarSFML::setSprite(const sf::Sprite &sprite) {
    PlayerCarSFML::sprite = sprite;
}

void roadfighterSFML::PlayerCarSFML::set_position(float x, float y) {
    sprite.setPosition(x, y);
}





