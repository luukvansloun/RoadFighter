//
// Created by luuk on 27-11-18.
//

#include "Transformation.h"

//std::shared_ptr<Transformation> Transformation::getInstance() {
//    static std::shared_ptr<Transformation> instance;
//    return instance;
//}

Transformation::~Transformation() {}


std::shared_ptr<Transformation> Transformation::instance = nullptr;

std::shared_ptr<Transformation> Transformation::getInstance() {
    if(instance == nullptr) {
        instance = std::make_shared<Transformation>();
    }

    return instance;
}

