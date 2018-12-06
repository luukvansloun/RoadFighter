//
// Created by luuk on 26-11-18.
#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include <iostream>

namespace roadfighter {
    class Entity {
    private:
        float x = 0;
        float y = 0;

    public:
        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

        virtual void change_position() {};

        virtual void draw() {};
    };
}

#endif //ROADFIGHTER_ENTITY_H
