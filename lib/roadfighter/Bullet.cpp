//
// Created by luuk on 19-12-18.
//

#include "Bullet.h"

double roadfighter::Bullet::getSpeed() const {
    return speed;
}

void roadfighter::Bullet::setSpeed(double speed) {
    Bullet::speed = speed;
}

std::string roadfighter::Bullet::get_type() {
    return "Bullet";
}