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


namespace roadfighterSFML {

    class RacingCarSFML : public roadfighter::RacingCar {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;

    public:
        RacingCarSFML(std::shared_ptr<sf::RenderWindow> window);

        virtual ~RacingCarSFML();

        void change_position() override;

        void draw();

        float getWidth() const;

        float getHeight() const;
    };
}

#endif //ROADFIGHTER_RACINGCARSFML_H
