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
    public:
        double getSpeed() const;

        void setSpeed(double speed);

        int getMax_speed() const;

        void draw() {};

    private:
        double speed = 0;
        int max_speed = 400;
    };
}


#endif //ROADFIGHTER_PLAYERCARENTITY_H
