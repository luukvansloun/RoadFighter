//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARSFML_H
#define ROADFIGHTER_PLAYERCARSFML_H

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <PlayerCar.h>
#include "../main/Transformation.h"

namespace roadfighterSFML {

    class PlayerCarSFML : public roadfighter::PlayerCar {
    public:
        PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window);

        virtual ~PlayerCarSFML();

        void change_position() override;

        void draw();

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;
    };


}

#endif //ROADFIGHTER_PLAYERCARSFML_H
