//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_TRUCK_H
#define ROADFIGHTER_TRUCK_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class Truck : public Entity {
    private:
        const double speed = 200;

    public:
        double getSpeed() const override;

        void draw() {};

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};
    };
}

#endif //ROADFIGHTER_TRUCK_H
