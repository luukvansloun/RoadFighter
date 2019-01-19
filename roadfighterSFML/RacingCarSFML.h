/**
 * @file RacingCarSFML.h
 *
 * @brief Header file for RacingCarSFML class
 *
 * @class roadfighterSFML::RacingCarSFML
 *
 * @brief This Class contains all the SFML functionalities for Racing cars.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_RACINGCARSFML_H
#define ROADFIGHTER_RACINGCARSFML_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <RacingCar.h>
#include "EntityFactory.h"
#include <Transformation.h>
#include "Explosion.h"


namespace roadfighterSFML {

    class RacingCarSFML : public roadfighter::RacingCar {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<roadfighterSFML::Explosion> explosion;

    public:
        /**
        * @fn RacingCarSFML(std::shared_ptr<sf::RenderWindow> window)
        * @param std::shared_ptr<sf::RenderWindow> window
        * @brief Constructor for the RacingCarSFML Class
        * @post New RacingCarSFML object has been created
        */
        RacingCarSFML(std::shared_ptr<sf::RenderWindow> window);

        /**
        * @fn ~RacingCarSFML()
        * @brief Destructor for the RacingCarSFML Class
        * @post RacingCarSFML object has been destroyed
        */
        virtual ~RacingCarSFML();

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

#endif //ROADFIGHTER_RACINGCARSFML_H
