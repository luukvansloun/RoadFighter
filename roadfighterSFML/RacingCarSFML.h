//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_RACINGCARSFML_H
#define ROADFIGHTER_RACINGCARSFML_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "EntityFactory.h"


namespace roadfighterSFML {

    class RacingCarSFML : public roadfighter::Entity {
    public:
        RacingCarSFML();

        virtual ~RacingCarSFML();

        void setup_SFML();

    private:
        sf::Texture t;
    };
}

#endif //ROADFIGHTER_RACINGCARSFML_H
