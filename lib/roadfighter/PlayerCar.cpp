//
// Created by luuk on 5-12-18.
//

#include "PlayerCar.h"

// PLAYERCAR ENTITY CLASS

roadfighter::PlayerCar::PlayerCar() {}

roadfighter::PlayerCar::~PlayerCar() {

}

float roadfighter::PlayerCar::getX() const {
    return x;
}

void roadfighter::PlayerCar::setX(float x) {
    PlayerCar::x = x;
}

float roadfighter::PlayerCar::getY() const {
    return y;
}

void roadfighter::PlayerCar::setY(float y) {
    PlayerCar::y = y;
}

int roadfighter::PlayerCar::getSpeed() const {
    return speed;
}

void roadfighter::PlayerCar::setSpeed(int speed) {
    PlayerCar::speed = speed;
}

int roadfighter::PlayerCar::getMax_speed() const {
    return max_speed;
}





