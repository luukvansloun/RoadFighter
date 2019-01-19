/**
 * @file PlayerCarSFML.h
 *
 * @brief Header file for PlayerCarSFML class
 *
 * @class roadfighterSFML::PlayerCarSFML
 *
 * @brief This Class contains all the SFML functionalities for the Player car.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_PLAYERCARSFML_H
#define ROADFIGHTER_PLAYERCARSFML_H

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <PlayerCar.h>
#include <Transformation.h>
#include "Explosion.h"

namespace roadfighterSFML {

    class PlayerCarSFML : public roadfighter::PlayerCar {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<roadfighterSFML::Explosion> explosion;

    public:
        /**
        * @fn PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window)
        * @param std::shared_ptr<sf::RenderWindow> window
        * @brief Constructor for the PlayerCarSFML Class
        * @post New PlayerCarSFML object has been created
        */
        PlayerCarSFML(std::shared_ptr<sf::RenderWindow> window);

        /**
        * @fn ~PlayerCarSFML()
        * @brief Destructor for the PlayerCarSFML Class
        * @post PlayerCarSFML object has been destroyed
        */
        virtual ~PlayerCarSFML();

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
    };
}

#endif //ROADFIGHTER_PLAYERCARSFML_H
