//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_RACINGCARSFML_H
#define ROADFIGHTER_RACINGCARSFML_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>


namespace roadfighterSFML {

    class RacingCarSFML {
    public:
        RacingCarSFML();

        virtual ~RacingCarSFML();

        void setup_SFML();

    private:
        sf::Texture t;
    };

    class RacingCarSFML_Factory {
    public:
        std::shared_ptr<RacingCarSFML> create_entity();
    };
}

#endif //ROADFIGHTER_RACINGCARSFML_H
