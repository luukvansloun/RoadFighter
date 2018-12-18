//
// Created by luuk on 26-11-18.
//

#include "Entity.h"

float roadfighter::Entity::getX() const {
    return x;
}

void roadfighter::Entity::setX(float x) {
    Entity::x = x;
}

float roadfighter::Entity::getY() const {
    return y;
}

void roadfighter::Entity::setY(float y) {
    Entity::y = y;
}

const std::pair<bool, std::string> &roadfighter::Entity::getCrash() const {
    return crash;
}

void roadfighter::Entity::setCrash(const std::pair<bool, std::string> &crash) {
    Entity::crash = crash;
}

bool roadfighter::Entity::isCrashed() const {
    return crashed;
}

void roadfighter::Entity::setCrashed(bool crashed) {
    Entity::crashed = crashed;
}
