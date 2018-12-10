//
// Created by luuk on 5-12-18.
//

#include "PlayerCar.h"

// PLAYERCAR ENTITY CLASS

double roadfighter::PlayerCar::getSpeed() const {
    return speed;
}

void roadfighter::PlayerCar::setSpeed(double speed) {
    PlayerCar::speed = speed;
}

int roadfighter::PlayerCar::getMax_speed() const {
    return max_speed;
}

int roadfighter::PlayerCar::getDistance() const {
    return distance;
}

void roadfighter::PlayerCar::update_distance(double distance) {
    // Round the to add distance
    int addition = int(distance);

    PlayerCar::distance += addition;
}





