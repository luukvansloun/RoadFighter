//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARSFML_H
#define ROADFIGHTER_PLAYERCARSFML_H

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <PlayerCar.h>
#include "EntityFactory.h"

namespace roadfighterSFML {

    class PlayerCarSFML : public roadfighter::PlayerCar {
    public:
        PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window);

        virtual ~PlayerCarSFML();

        void setup_sfml(std::string path_to_sprite, float x, float y);

        const sf::Sprite &getSprite() const;

        void setSprite(const sf::Sprite &sprite);

        void set_position(float x, float y);

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;
    };


}

#endif //ROADFIGHTER_PLAYERCARSFML_H
