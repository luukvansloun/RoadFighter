//
// Created by luuk on 27-11-18.
//

#include "Transformation.h"

Transformation* Transformation::transformation = nullptr;

Transformation::Transformation() {}

Transformation::~Transformation() {}

Transformation* Transformation::Instance() {
    if(transformation == nullptr) {
        transformation = new Transformation;
    }

    return transformation;
}

