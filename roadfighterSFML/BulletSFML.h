/**
 * @file BulletSFML.h
 *
 * @brief Header file for BulletSFML class
 *
 * @class roadfighterSFML::BulletSFML
 *
 * @brief This Class contains all the SFML functionalities for Bullets.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_BULLETSFML_H
#define ROADFIGHTER_BULLETSFML_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <Bullet.h>
#include <Transformation.h>
#include <Random.h>

/**
* @namespace roadfighterSFML
* @brief This Namespace contains all elements to complete the graphical aspect of the roadfighter library
*/
namespace roadfighterSFML {
    class BulletSFML : public roadfighter::Bullet {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;

    public:
        /**
        * @fn BulletSFML(std::shared_ptr<sf::RenderWindow> window)
        * @param std::shared_ptr<sf::RenderWindow> window
        * @brief Constructor for the BulletSFML Class
        * @post New BulletSFML object has been created
        */
        BulletSFML(std::shared_ptr<sf::RenderWindow> window);

        /**
        * @fn void change_position() override
        * @brief Relocates to the new pixel coördinates calculated from the used coördinate system
        */
        void change_position() override;

        /**
        * @fn void draw() override
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
        * @fn float getHeight() const override
        * @brief Returns the SFML object height
        * @return float
        */
        float getHeight() const override;
    };
}


#endif //ROADFIGHTER_BULLETSFML_H
