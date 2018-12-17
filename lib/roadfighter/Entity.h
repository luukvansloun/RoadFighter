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
        std::pair<bool, std::string> crash = std::make_pair(false, "");

    public:
        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

        const std::pair<bool, std::string> &getCrash() const;

        void setCrash(const std::pair<bool, std::string> &crash);

        virtual void change_position() {};

        virtual void draw() {};

        virtual double getSpeed() const {return 0;};

        virtual void setSpeed(double speed) {};

        virtual int getMax_speed() const {return 0;};

        virtual double getDistance() const {return 0;};

        virtual void update_distance(double distance) {};

        virtual int getHealth() const {return 0;};

        virtual void decrease_speed(int val) {};

        virtual int getFuel() const {return 0;};

        virtual void setFuel(int fuel) {};

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};
    };
}

#endif //ROADFIGHTER_ENTITY_H
