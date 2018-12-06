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

        void setup_sfml(std::string path_to_sprite, float x, float y);

        const sf::Sprite &getSprite() const;

        void setSprite(const sf::Sprite &sprite);

        void set_position(float x, float y);

    private:
        sf::Texture texture;
        sf::Sprite sprite;
    };

    class PlayerCarSFML_Factory {
    public:
        std::shared_ptr<PlayerCarSFML> create_entity();
    };
}

#endif //ROADFIGHTER_PLAYERCARSFML_H
