//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_RACINGCARENTITY_H
#define ROADFIGHTER_RACINGCARENTITY_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class RacingCar : public Entity {
    private:
        double speed = 300;
        int health = 3;
        double distance = 0;

    public:
        double getSpeed() const override;

        void setSpeed(double speed) override;

        void draw() override {};

        double getDistance() const override;

        void update_distance(double distance) override;

        int getHealth() const override;

        void decrease_speed(int val);

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};
    };
}


#endif //ROADFIGHTER_RACINGCARENTITY_H
