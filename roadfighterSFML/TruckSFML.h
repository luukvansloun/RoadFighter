//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_TRUCKSFML_H
#define ROADFIGHTER_TRUCKSFML_H

#include <iostream>
#include <memory>
#include <Truck.h>
#include <SFML/Graphics.hpp>
#include "../main/Singletons/Transformation.h"
#include "../main/Singletons/Random.h"

namespace roadfighterSFML {
    class TruckSFML : public roadfighter::Truck {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;

    public:
        TruckSFML(std::shared_ptr<sf::RenderWindow> window);

        void change_position();

        void draw();

        float getWidth() const;

        float getHeight() const;
    };
}


#endif //ROADFIGHTER_TRUCKSFML_H
