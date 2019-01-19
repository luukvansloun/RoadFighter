/**
 * @file Bullet.h
 *
 * @brief Header file for Bullet class
 *
 * @class roadfighter::Bullet
 *
 * @brief This Class contains all the functionalities of the Bullet object.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_BULLET_H
#define ROADFIGHTER_BULLET_H

#include <iostream>
#include <memory>
#include "Entity.h"

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class Bullet : public roadfighter::Entity {
    private:
        double speed = 500;
        int health = 1;

    public:
        /**
        * @fn std::string get_type() override
        * @brief Returns the Bullet's type
        * @return std::string
        */
        std::string get_type() override;

        /**
        * @fn double getSpeed() const override
        * @brief Returns the Bullet's speed
        * @return double
        */
        double getSpeed() const override;

        /**
        * @fn void setSpeed(double speed) override;
        * @param double speed
        * @brief Sets the Bullet's speed
        */
        void setSpeed(double speed) override;

        /**
        * @fn void draw() override {};
        * @brief Declaration of the draw function (Only used in SFML objects)
        */
        void draw() override {};

        /**
        * @fn float getWidth() const override {return 0;};
        * @brief Declaration of the getWidth function (Only used in SFML objects)
        */
        float getWidth() const override {return 0;};

        /**
        * @fn float getHeight() const override {return 0;};
        * @brief Declaration of the getHeight function (Only used in SFML objects)
        */
        float getHeight() const override {return 0;};

        /**
        * @fn int getHealth() const override
        * @brief Returns the Bullet's health
        * @return int
        */
        int getHealth() const override;

        /**
        * @fn void setHealth(int health) override;
        * @param int health
        * @brief Sets the Bullet's health
        */
        void setHealth(int health) override;
    };
}


#endif //ROADFIGHTER_BULLET_H
