//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_LORRYSFML_H
#define ROADFIGHTER_LORRYSFML_H

#include <iostream>
#include <memory>
#include <Lorry.h>
#include <SFML/Graphics.hpp>
#include <Transformation.h>
#include <Random.h>
#include "Explosion.h"

namespace roadfighterSFML {
    class LorrySFML : public roadfighter::Lorry {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<roadfighterSFML::Explosion> explosion;

    public:
        LorrySFML(std::shared_ptr<sf::RenderWindow> window);

        void change_position();

        void draw();

        float getWidth() const;

        float getHeight() const;

        void update(bool crashed) override;

        bool explosion_finished() override;
    };
}

#endif //ROADFIGHTER_LORRYSFML_H
