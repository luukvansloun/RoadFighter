/**
 * @file TruckSFML.h
 *
 * @brief Header file for TruckSFML class
 *
 * @class roadfighterSFML::TruckSFML
 *
 * @brief This Class contains all the SFML functionalities for Trucks.
 *
 * @authors Luuk van Sloun
 */

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
        /**
        * @fn TruckSFML(std::shared_ptr<sf::RenderWindow> window)
        * @param std::shared_ptr<sf::RenderWindow> window
        * @brief Constructor for the TruckSFML Class
        * @post New TruckSFML object has been created
        */
        TruckSFML(std::shared_ptr<sf::RenderWindow> window);

        /**
        * @fn void change_position()
        * @brief Relocates to the new pixel coördinates calculated from the used coördinate system
        */
        void change_position() override;

        /**
        * @fn void draw()
        * @brief Calls the SFML draw functionality
        */
        void draw() override;

        /**
        * @fn float getWidth()
        * @brief Returns the SFML object width
        * @return float
        */
        float getWidth() const override;

        /**
        * @fn float getHeight()
        * @brief Returns the SFML object height
        * @return float
        */
        float getHeight() const override;

        /**
        * @fn void update(bool crashed)
        * @param bool crashed
        * @brief Calls the Explosion update function in case of a 'crash'
        */
        void update(bool crashed) override;

        /**
        * @fn bool explosion_finished()
        * @brief Returns True if the Explosion animation has finished
        * @return bool
        */
        bool explosion_finished() override;
    };
}


#endif //ROADFIGHTER_TRUCKSFML_H
