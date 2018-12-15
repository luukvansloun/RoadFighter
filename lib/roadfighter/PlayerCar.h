//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARENTITY_H
#define ROADFIGHTER_PLAYERCARENTITY_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class PlayerCar : public Entity {
    private:
        double speed = 0;
        const int max_speed = 300;
        double distance = 0;
        int health = 3;
        int fuel = 100;

    public:
        double getSpeed() const override;

        void setSpeed(double speed) override;

        int getMax_speed() const override;

        void draw() override {};

        double getDistance() const override;

        void update_distance(double distance) override;

        int getHealth() const override;

        int getFuel() const override;

        void setFuel(int fuel) override;

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};
    };
}


#endif //ROADFIGHTER_PLAYERCARENTITY_H
