//
// Created by luuk on 10-12-18.
//

#include "Truck.h"

double roadfighter::Truck::getSpeed() const {
    return speed;
}

void roadfighter::Truck::setSpeed(double speed) {
    Truck::speed = speed;
}

std::string roadfighter::Truck::get_type() {
    return "Truck";
}

int roadfighter::Truck::getHealth() const {
    return health;
}

void roadfighter::Truck::setHealth(int health) {
    Truck::health = health;
}



