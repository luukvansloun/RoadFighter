//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARENTITY_H
#define ROADFIGHTER_PLAYERCARENTITY_H

#include <iostream>
#include <memory>
#include <vector>
#include "Entity.h"

class Observer;

namespace roadfighter {
    class PlayerCar : public Entity {
    private:
        double speed = 0;
        const int max_speed = 300;
        double distance = 0;
        int health = 3;
        int fuel = 100;
        bool shoot = false;
        int bullets = 25;
        double score = 0;
        std::vector<std::shared_ptr<Observer>> observers;

    public:
        std::string get_type() override;

        double getSpeed() const override;

        void setSpeed(double speed) override;

        int getMax_speed() const override;

        void draw() override {};

        double getDistance() const override;

        void update_distance(double distance) override;

        int getHealth() const override;

        void setHealth(int health) override;

        int getFuel() const override;

        void setFuel(int fuel) override;

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};

        bool isShoot() const override;

        void setShoot(bool shoot) override;

        int getBullets() const override;

        void setBullets(int bullets) override;

        void increase_score(double value);

        double getScore();

        void attach(std::shared_ptr<Observer> obs);

        void notify();
    };
}


#endif //ROADFIGHTER_PLAYERCARENTITY_H
