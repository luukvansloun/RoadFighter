/**
 * @file Random.h
 *
 * @brief Header file for Random class
 *
 * @class Random
 *
 * @brief This Class contains all the functionalities of the Random Singleton.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_RANDOM_H
#define ROADFIGHTER_RANDOM_H

#include <iostream>
#include <memory>
#include <ctime>

class Random {
private:
    Random()=default;

public:
    Random(Random const&) = delete;
    void operator=(Random const&) = delete;

    /**
    * @fn static Random& get_instance()
    * @brief Returns the Random instance
    * @return static Random&
    */
    static Random& get_instance() {
        static Random instance;
        return instance;
    }

    /**
    * @fn float get_random_x()
    * @brief Returns the a random x value between the borders of the road
    * @return float
    */
    float get_random_x();
};


#endif //ROADFIGHTER_RANDOM_H
