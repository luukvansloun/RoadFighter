//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_TRUCK_H
#define ROADFIGHTER_TRUCK_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class Truck : public Entity{
    private:
        int speed = 100;

    public:
        void draw() {};
    };
}

#endif //ROADFIGHTER_TRUCK_H
