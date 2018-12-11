//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_RACINGCARSFML_H
#define ROADFIGHTER_RACINGCARSFML_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "EntityFactory.h"
#include "../main/Transformation.h"


namespace roadfighterSFML {

    class RacingCarSFML : public roadfighter::Entity {
    public:
        RacingCarSFML(std::shared_ptr<sf::RenderWindow> window);

        virtual ~RacingCarSFML();

        void change_position() override;

        void draw();

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;
    };
}

#endif //ROADFIGHTER_RACINGCARSFML_H
