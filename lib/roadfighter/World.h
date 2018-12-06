//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class World : public roadfighter::Entity {
    private:
        float x;
        float y;

    public:
        World();

        virtual ~World();
    };
}


#endif //ROADFIGHTER_WORLD_H
