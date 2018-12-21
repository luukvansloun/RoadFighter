//
// Created by luuk on 10-12-18.
//

#include "Lorry.h"

double roadfighter::Lorry::getSpeed() const {
    return speed;
}

void roadfighter::Lorry::setSpeed(double speed) {
    Lorry::speed = speed;
}

std::string roadfighter::Lorry::get_type() {
    return "Lorry";
}

int roadfighter::Lorry::getHealth() const {
    return health;
}

void roadfighter::Lorry::setHealth(int health) {
    Lorry::health = health;
}
