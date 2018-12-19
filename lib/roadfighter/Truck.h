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
        double speed = 200;

    public:
        std::string get_type() override;

        double getSpeed() const override;

        void setSpeed(double speed) override;

        void draw() {};

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};
    };
}

#endif //ROADFIGHTER_TRUCK_H
