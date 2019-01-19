/**
 * @file LorrySFML.h
 *
 * @brief Header file for LorrySFML class
 *
 * @class roadfighterSFML::LorrySFML
 *
 * @brief This Class contains all the SFML functionalities for Lorries.
 *
 * @authors Luuk van Sloun
 */

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
        /**
        * @fn LorrySFML(std::shared_ptr<sf::RenderWindow> window)
        * @param std::shared_ptr<sf::RenderWindow> window
        * @brief Constructor for the LorrySFML Class
        * @post New LorrySFML object has been created
        */
        LorrySFML(std::shared_ptr<sf::RenderWindow> window);

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
        * @fn float getWidth() const override
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

#endif //ROADFIGHTER_LORRYSFML_H
