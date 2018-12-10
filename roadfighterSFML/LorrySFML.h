//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_LORRYSFML_H
#define ROADFIGHTER_LORRYSFML_H

#include <iostream>
#include <memory>
#include <Lorry.h>
#include <SFML/Graphics.hpp>
#include "../main/Transformation.h"
#include "../main/Random.h"

namespace roadfighterSFML {
    class LorrySFML : public roadfighter::Lorry {
    public:
        LorrySFML(std::shared_ptr<sf::RenderWindow> window);

        void change_position();

        void draw();

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;
    };
}

#endif //ROADFIGHTER_LORRYSFML_H
