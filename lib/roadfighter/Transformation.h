/**
 * @file Transformation.h
 *
 * @brief Header file for Transformation class
 *
 * @class Transformation
 *
 * @brief This Class contains all the functionalities of the Transformation Singleton.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_TRANSFORMATION_H
#define ROADFIGHTER_TRANSFORMATION_H

#include <iostream>
#include <memory>

class Transformation {
private:
    Transformation();

public:
    Transformation(Transformation const&) = delete;
    void operator=(Transformation const&) = delete;

    /**
    * @fn static Transformation& get_instance()
    * @brief Returns the Transformation instance
    * @return static Transformation&
    */
    static Transformation& get_instance() {
        static Transformation instance;
        return instance;
    }

    /**
    * @fn std::pair<float, float> get_coordinates(std::pair<float, float> co, float x, float y)
    * @param std::pair<float, float> co
    * @param float x
    * @param float y
    * @brief Returns the pixel coördinates calculated by the standard coördinates [-4, 4]x[-3, 3]
    * @return std::pair<float, float>
    */
    std::pair<float, float> get_coordinates(std::pair<float, float> co, float x, float y);
};


#endif //ROADFIGHTER_TRANSFORMATION_H
