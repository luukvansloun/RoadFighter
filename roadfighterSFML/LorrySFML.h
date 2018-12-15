//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_LORRYSFML_H
#define ROADFIGHTER_LORRYSFML_H

#include <iostream>
#include <memory>
#include <Lorry.h>
#include <SFML/Graphics.hpp>
#include "../main/Singletons/Transformation.h"
#include "../main/Singletons/Random.h"

namespace roadfighterSFML {
    class LorrySFML : public roadfighter::Lorry {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;

    public:
        LorrySFML(std::shared_ptr<sf::RenderWindow> window);

        void change_position();

        void draw();

        float getWidth() const;

        float getHeight() const;
    };
}

#endif //ROADFIGHTER_LORRYSFML_H
