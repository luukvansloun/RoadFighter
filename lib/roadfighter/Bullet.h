//
// Created by luuk on 19-12-18.
//

#ifndef ROADFIGHTER_BULLET_H
#define ROADFIGHTER_BULLET_H

#include <iostream>
#include <memory>
#include "Entity.h"

namespace roadfighter {
    class Bullet : public roadfighter::Entity {
    private:
        double speed = 500;

    public:
        std::string get_type() override;

        double getSpeed() const override;

        void setSpeed(double speed) override;

        void draw() {};

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};
    };
}


#endif //ROADFIGHTER_BULLET_H
