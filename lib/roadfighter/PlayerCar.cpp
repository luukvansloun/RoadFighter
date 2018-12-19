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

double roadfighter::PlayerCar::getDistance() const {
    return distance;
}

void roadfighter::PlayerCar::update_distance(double distance) {
    PlayerCar::distance += distance;
}

int roadfighter::PlayerCar::getHealth() const {
    return health;
}

int roadfighter::PlayerCar::getFuel() const {
    return fuel;
}

void roadfighter::PlayerCar::setFuel(int fuel) {
    PlayerCar::fuel = fuel;
}

std::string roadfighter::PlayerCar::get_type() {
    return "PlayerCar";
}





