//
// Created by luuk on 27-11-18.
//

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

    static Transformation& get_instance() {
        static Transformation instance;
        return instance;
    }


    std::pair<float, float> get_coordinates(std::pair<float, float> co, float x, float y);
};


#endif //ROADFIGHTER_TRANSFORMATION_H
