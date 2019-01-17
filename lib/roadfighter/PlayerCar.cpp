//
// Created by luuk on 5-12-18.
//

#include "PlayerCar.h"
#include "Observer.h"

// PLAYERCAR ENTITY CLASS

double roadfighter::PlayerCar::getSpeed() const {
    return speed;
}

void roadfighter::PlayerCar::setSpeed(double speed) {
    PlayerCar::speed = speed;

    if(PlayerCar::speed < 0) {
        PlayerCar::speed = 0;
    }
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

void roadfighter::PlayerCar::setHealth(int health) {
    PlayerCar::health = health;
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

bool roadfighter::PlayerCar::isShoot() const {
    return shoot;
}

void roadfighter::PlayerCar::setShoot(bool shoot) {
    PlayerCar::shoot = shoot;
}

int roadfighter::PlayerCar::getBullets() const {
    return bullets;
}

void roadfighter::PlayerCar::setBullets(int bullets) {
    PlayerCar::bullets = bullets;
}

void roadfighter::PlayerCar::attach(std::shared_ptr<Observer> obs) {
    observers.push_back(obs);
}

void roadfighter::PlayerCar::increase_score(double value) {
    score += value;
    if(score < 0) {
        score = 0;
    }
    notify();
}

double roadfighter::PlayerCar::getScore() {
    return score;
}

void roadfighter::PlayerCar::notify() {
    for(const auto& obs : observers) {
        obs->update();
    }
}





