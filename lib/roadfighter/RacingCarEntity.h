//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_RACINGCARENTITY_H
#define ROADFIGHTER_RACINGCARENTITY_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class RacingCarEntity : public Entity {
    public:
        RacingCarEntity();

        virtual ~RacingCarEntity();

        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

    private:
        float x;
        float y;
    };

    class RacingCarEntity_Factory {
    public:
        RacingCarEntity_Factory();

        std::shared_ptr<RacingCarEntity> create_entity();
    };
}


#endif //ROADFIGHTER_RACINGCARENTITY_H
