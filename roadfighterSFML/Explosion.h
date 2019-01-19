/**
 * @file Explosion.h
 *
 * @brief Header file for Explosion class
 *
 * @class roadfighterSFML::Explosion
 *
 * @brief This Class contains all the SFML functionalities for Explosions.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_EXPLOSION_H
#define ROADFIGHTER_EXPLOSION_H

#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

/**
* @namespace roadfighterSFML
* @brief This Namespace contains all elements to complete the graphical aspect of the roadfighter library
*/
namespace roadfighterSFML {
    class Explosion {
    private:
        std::chrono::milliseconds total_time;
        std::chrono::milliseconds switch_time;
        std::chrono::milliseconds current_time;
        int current_image;

    public:
        /**
        * @fn Explosion()
        * @brief Constructor for the Explosion Class
        * @post New Explosion object has been created
        */
        Explosion();

        /**
        * @fn ~Explosion()
        * @brief Destructor for the Explosion Class
        * @post Explosion object has been destroyed
        */
        virtual ~Explosion()=default;

        sf::IntRect texture_rect;

        bool finished = false;

        /**
        * @fn void Update()
        * @brief Updates to the current state of the Explosion animation
        */
        void Update();
    };
}



#endif //ROADFIGHTER_EXPLOSION_H
