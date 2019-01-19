/**
 * @file Truck.h
 *
 * @brief Header file for Truck class
 *
 * @class roadfighter::Truck
 *
 * @brief This Class contains all the functionalities of the Truck object.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_TRUCK_H
#define ROADFIGHTER_TRUCK_H

#include <iostream>
#include <memory>
#include "Entity.h"

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class Truck : public Entity {
    private:
        double speed = 200;
        int health = 2;

    public:
        /**
        * @fn std::string get_type() override
        * @brief Returns the Truck's type
        * @return std::string
        */
        std::string get_type() override;

        /**
        * @fn double getSpeed() const override
        * @brief Returns the Truck's speed
        * @return double
        */
        double getSpeed() const override;

        /**
        * @fn void setSpeed(double speed) override;
        * @param double speed
        * @brief Sets the Truck's speed
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
        * @brief Returns the Truck's health
        * @return int
        */
        int getHealth() const override;

        /**
        * @fn void setHealth(int health) override;
        * @param int health
        * @brief Sets the Truck's health
        */
        void setHealth(int health) override;
    };
}

#endif //ROADFIGHTER_TRUCK_H
