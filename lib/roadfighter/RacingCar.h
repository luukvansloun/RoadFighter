/**
 * @file RacingCar.h
 *
 * @brief Header file for RacingCar class
 *
 * @class roadfighter::RacingCar
 *
 * @brief This Class contains all the functionalities of the RacingCar object.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_RACINGCARENTITY_H
#define ROADFIGHTER_RACINGCARENTITY_H

#include <iostream>
#include <memory>
#include "Entity.h"

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class RacingCar : public Entity {
    private:
        double speed = 300;
        int health = 3;
        double distance = 0;

    public:
        /**
        * @fn std::string get_type() override
        * @brief Returns the Racing car's type
        * @return std::string
        */
        std::string get_type() override;

        /**
        * @fn double getSpeed() const override
        * @brief Returns the Racing car's speed
        * @return double
        */
        double getSpeed() const override;

        /**
        * @fn void setSpeed(double speed) override;
        * @param double speed
        * @brief Sets the Racing car's speed
        */
        void setSpeed(double speed) override;

        /**
        * @fn void draw() override {};
        * @brief Declaration of the draw function (Only used in SFML objects)
        */
        void draw() override {};

        /**
        * @fn double getDistance() const override;
        * @brief Returns the Racing car's distance
        * @return double
        */
        double getDistance() const override;

        /**
        * @fn void update_distance(double distance) override;
        * @param double distance
        * @brief Updates the Racing car's distance by the given value
        */
        void update_distance(double distance) override;

        /**
        * @fn int getHealth() const override
        * @brief Returns the Racing car's health
        * @return int
        */
        int getHealth() const override;

        /**
        * @fn void setHealth(int health) override;
        * @param int health
        * @brief Sets the Racing car's health
        */
        void setHealth(int health) override;

        /**
        * @fn void decrease_speed(int val) override;
        * @param int val
        * @brief Decreases the Racing car's speed by the given value
        */
        void decrease_speed(int val) override;

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
    };
}


#endif //ROADFIGHTER_RACINGCARENTITY_H
