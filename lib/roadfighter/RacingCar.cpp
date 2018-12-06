//
// Created by luuk on 5-12-18.
//

#include "RacingCar.h"

// RACINGCAR ENTITY CLASS

roadfighter::RacingCar::RacingCar() {}

roadfighter::RacingCar::~RacingCar() {

}

float roadfighter::RacingCar::getX() const {
    return x;
}

void roadfighter::RacingCar::setX(float x) {
    RacingCar::x = x;
}

float roadfighter::RacingCar::getY() const {
    return y;
}

void roadfighter::RacingCar::setY(float y) {
    RacingCar::y = y;
}