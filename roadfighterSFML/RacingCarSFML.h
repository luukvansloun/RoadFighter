//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_RACINGCARSFML_H
#define ROADFIGHTER_RACINGCARSFML_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <RacingCar.h>
#include "EntityFactory.h"
#include "../main/Singletons/Transformation.h"
#include "Explosion.h"


namespace roadfighterSFML {

    class RacingCarSFML : public roadfighter::RacingCar {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<roadfighterSFML::Explosion> explosion;

    public:
        RacingCarSFML(std::shared_ptr<sf::RenderWindow> window);

        virtual ~RacingCarSFML();

        void change_position() override;

        void draw() override;

        float getWidth() const override;

        float getHeight() const override;

        void update(bool crashed) override;

        bool explosion_finished() override;
    };
}

#endif //ROADFIGHTER_RACINGCARSFML_H
