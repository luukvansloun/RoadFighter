//
// Created by luuk on 27-11-18.
//

#include "Transformation.h"

Transformation::Transformation() {}

std::pair<float, float> Transformation::get_coordinates(std::pair<float, float> co, float x, float y) {
    float x_width = x / 8;
    float y_width = y / 6;

    float pos_x = (co.first + 4.0) * x_width;
    float pos_y = (3.0 - co.second) * y_width;

    return std::make_pair(pos_x, pos_y);
}




