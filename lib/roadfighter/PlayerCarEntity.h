//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARENTITY_H
#define ROADFIGHTER_PLAYERCARENTITY_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class PlayerCarEntity : public roadfighter::Entity {
    public:
        PlayerCarEntity();

        virtual ~PlayerCarEntity();

        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

    private:
        float x;
        float y;
    };

    class PlayerCarEntity_Factory {
    public:
        PlayerCarEntity_Factory();

        std::shared_ptr<PlayerCarEntity> create_entity();
    };
}


#endif //ROADFIGHTER_PLAYERCARENTITY_H
