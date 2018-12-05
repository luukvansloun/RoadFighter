//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARSFML_H
#define ROADFIGHTER_PLAYERCARSFML_H

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

namespace roadfighterSFML {

    class PlayerCarSFML {
    public:
        PlayerCarSFML();

        virtual ~PlayerCarSFML();

        void setup_SFML();

    private:
        sf::Texture t;
    };

    class PlayerCarSFML_Factory {
    public:
        std::shared_ptr<PlayerCarSFML> create_entity();
    };
}

#endif //ROADFIGHTER_PLAYERCARSFML_H
