//
// Created by luuk on 5-12-18.
//

#include "RacingCar.h"

// RACINGCAR ENTITY CLASS

double roadfighter::RacingCar::getSpeed() const {
    return speed;
}

void roadfighter::RacingCar::setSpeed(double speed) {
    RacingCar::speed = speed;
}

double roadfighter::RacingCar::getDistance() const {
    return distance;
}

void roadfighter::RacingCar::update_distance(double distance) {
    RacingCar::distance += distance;
}

int roadfighter::RacingCar::getHealth() const {
    return health;
}

void roadfighter::RacingCar::decrease_speed(int val) {
    RacingCar::speed -= val;
}
