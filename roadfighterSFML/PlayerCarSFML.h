//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARSFML_H
#define ROADFIGHTER_PLAYERCARSFML_H

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <PlayerCar.h>
#include <Transformation.h>
#include "Explosion.h"

namespace roadfighterSFML {

    class PlayerCarSFML : public roadfighter::PlayerCar {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<roadfighterSFML::Explosion> explosion;

    public:
        PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window);

        virtual ~PlayerCarSFML();

        void change_position() override;

        void draw();

        float getWidth() const;

        float getHeight() const;

        void update(bool crashed);
    };


}

#endif //ROADFIGHTER_PLAYERCARSFML_H
