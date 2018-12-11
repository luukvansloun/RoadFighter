//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_LORRY_H
#define ROADFIGHTER_LORRY_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class Lorry : public Entity {
    private:
        const double speed = 90;

    public:
        double getSpeed() const override;

        void draw() {};
    };
}

#endif //ROADFIGHTER_LORRY_H
