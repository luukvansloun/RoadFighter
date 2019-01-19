/**
 * @file PlayerCar.h
 *
 * @brief Header file for PlayerCar class
 *
 * @class roadfighter::PlayerCar
 *
 * @brief This Class contains all the functionalities of the PlayerCar object.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_PLAYERCARENTITY_H
#define ROADFIGHTER_PLAYERCARENTITY_H

#include <iostream>
#include <memory>
#include <vector>
#include "Entity.h"

class Observer;

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class PlayerCar : public Entity {
    private:
        double speed = 0;
        const int max_speed = 300;
        double distance = 0;
        int health = 3;
        int fuel = 100;
        bool shoot = false;
        int bullets = 30;
        double score = 0;
        std::vector<std::shared_ptr<Observer>> observers;

    public:
        /**
        * @fn std::string get_type() override
        * @brief Returns the Player car's type
        * @return std::string
        */
        std::string get_type() override;

        /**
        * @fn double getSpeed() const override
        * @brief Returns the Player car's speed
        * @return double
        */
        double getSpeed() const override;

        /**
        * @fn void setSpeed(double speed) override
        * @param double speed
        * @brief Sets the Player car's speed
        */
        void setSpeed(double speed) override;

        /**
        * @fn int getMax_speed() const override
        * @brief Returns the Player car's max speed
        * @return int
        */
        int getMax_speed() const override;

        /**
        * @fn void draw() override
        * @brief Declaration of the draw function (Only used in SFML objects)
        */
        void draw() override {};

        /**
        * @fn double getDistance() const override
        * @brief Returns the Player car's distance
        * @return double
        */
        double getDistance() const override;

        /**
        * @fn void update_distance(double distance) override
        * @param double distance
        * @brief Updates the Player car's distance by the given value
        */
        void update_distance(double distance) override;

        /**
        * @fn int getHealth() const override
        * @brief Returns the Player car's health
        * @return int
        */
        int getHealth() const override;

        /**
        * @fn void setHealth(int health) override
        * @param int health
        * @brief Sets the Player car's health
        */
        void setHealth(int health) override;

        /**
        * @fn int getFuel() const override
        * @brief Returns the Player car's fuel level
        * @return int
        */
        int getFuel() const override;

        /**
        * @fn void setFuel(int fuel) override
        * @param int fuel
        * @brief Sets the Player car's fuel level
        */
        void setFuel(int fuel) override;

        /**
        * @fn float getWidth() const override
        * @brief Declaration of the getWidth function (Only used in SFML objects)
        */
        float getWidth() const override {return 0;};

        /**
        * @fn float getHeight() const override
        * @brief Declaration of the getHeight function (Only used in SFML objects)
        */
        float getHeight() const override {return 0;};

        /**
        * @fn bool isShoot() const override
        * @brief Returns True if the Player car is allowed to shoot
        * @return bool
        */
        bool isShoot() const override;

        /**
        * @fn void setShoot(bool shoot) override
        * @param bool shoot
        * @brief Sets the boolean for the Player car's shooting ability
        */
        void setShoot(bool shoot) override;

        /**
        * @fn int getBullets() const override
        * @brief Returns the Player car's amount of bullets
        * @return int
        */
        int getBullets() const override;

        /**
        * @fn void setBullets(int bullets) override
        * @param int bullets
        * @brief Sets the Player car's amount of bullets
        */
        void setBullets(int bullets) override;

        /**
        * @fn void increase_score(double value) override
        * @param double value
        * @brief Increases the Player car's score by the given value
        */
        void increase_score(double value) override;

        /**
        * @fn double getScore() override
        * @brief Returns the Player car's score
        * @return double
        */
        double getScore() override;

        /**
        * @fn void attach(std::shared_ptr<Observer> obs) override
        * @param std::shared_ptr<Observer> obs
        * @brief Adds a score observer to the Player car
        */
        void attach(std::shared_ptr<Observer> obs) override;

        /**
        * @fn void notify()
        * @brief Notifies all attached observers that the score has been updated
        */
        void notify();
    };
}


#endif //ROADFIGHTER_PLAYERCARENTITY_H
