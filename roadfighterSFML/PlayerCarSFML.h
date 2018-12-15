//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARSFML_H
#define ROADFIGHTER_PLAYERCARSFML_H

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <PlayerCar.h>
#include "../main/Singletons/Transformation.h"

namespace roadfighterSFML {

    class PlayerCarSFML : public roadfighter::PlayerCar {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;

    public:
        PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window);

        virtual ~PlayerCarSFML();

        void change_position() override;

        void draw();

        float getWidth() const;

        float getHeight() const;
    };


}

#endif //ROADFIGHTER_PLAYERCARSFML_H
