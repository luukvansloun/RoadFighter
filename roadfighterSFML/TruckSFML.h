//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_TRUCKSFML_H
#define ROADFIGHTER_TRUCKSFML_H

#include <iostream>
#include <memory>
#include <Truck.h>
#include <SFML/Graphics.hpp>
#include "../main/Transformation.h"
#include "../main/Random.h"

namespace roadfighterSFML {
    class TruckSFML : public roadfighter::Truck {
    public:
        TruckSFML(std::shared_ptr<sf::RenderWindow> window);

        void change_position();

        void draw();

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<sf::RenderWindow> window;
    };
}


#endif //ROADFIGHTER_TRUCKSFML_H
