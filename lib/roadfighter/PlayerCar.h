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
        const int max_speed = 400;
        int distance = 0;

    public:
        double getSpeed() const;

        void setSpeed(double speed);

        int getMax_speed() const;

        void draw() {};

        int getDistance() const override;

        void update_distance(double distance) override;
    };
}


#endif //ROADFIGHTER_PLAYERCARENTITY_H
