//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_TRUCKSFML_H
#define ROADFIGHTER_TRUCKSFML_H

#include <iostream>
#include <memory>
#include <Truck.h>
#include <SFML/Graphics.hpp>
#include <Transformation.h>
#include <Random.h>
#include "Explosion.h"

namespace roadfighterSFML {
    class TruckSFML : public roadfighter::Truck {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<roadfighterSFML::Explosion> explosion;

    public:
        TruckSFML(std::shared_ptr<sf::RenderWindow> window);

        void change_position();

        void draw();

        float getWidth() const;

        float getHeight() const;

        void update(bool crashed) override;

        bool explosion_finished() override;
    };
}


#endif //ROADFIGHTER_TRUCKSFML_H
