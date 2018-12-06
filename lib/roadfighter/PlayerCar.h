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
        int getSpeed() const;

        void setSpeed(int speed);

        int getMax_speed() const;

        void draw() {};

    private:
        int speed = 0;
        int max_speed = 400;
    };
}


#endif //ROADFIGHTER_PLAYERCARENTITY_H
