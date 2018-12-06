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
    public:
        RacingCar();

        virtual ~RacingCar();

        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

    private:
        float x;
        float y;
    };
}


#endif //ROADFIGHTER_RACINGCARENTITY_H
