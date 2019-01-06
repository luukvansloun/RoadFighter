//
// Created by luuk on 26-11-18.
#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include <iostream>
#include <memory>

class Observer;

namespace roadfighter {
    class Entity {
    public:
        struct crash_struct {
            bool crash = false;
            std::string direction = "";
            std::shared_ptr<roadfighter::Entity> type = nullptr;
        };

    private:
        float x = 0;
        float y = 0;
        crash_struct crash;
        bool crashed = false;

    public:
        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

        const crash_struct &getCrash() const;

        void setCrash(const crash_struct &crash);

        bool isCrashed() const;

        void setCrashed(bool crashed);

        virtual std::string get_type() {return "";};

        virtual void change_position() {};

        virtual void draw() {};

        virtual double getSpeed() const {return 0;};

        virtual void setSpeed(double speed) {};

        virtual int getMax_speed() const {return 0;};

        virtual double getDistance() const {return 0;};

        virtual void update_distance(double distance) {};

        virtual int getHealth() const {return 0;};

        virtual void setHealth(int health) {};

        virtual void decrease_speed(int val) {};

        virtual int getFuel() const {return 0;};

        virtual void setFuel(int fuel) {};

        virtual float getWidth() const {return 0;};

        virtual float getHeight() const {return 0;};

        virtual void update(bool crashed) {};

        virtual bool explosion_finished() {return false;};

        virtual bool isShoot() const {return false;};

        virtual void setShoot(bool shoot) {};

        virtual int getBullets() const {return 0;};

        virtual void setBullets(int bullets) {};

        virtual void attach(const std::shared_ptr<Observer> obs) {};

        virtual void update() {};

        virtual int getScore() {return 0;};

        virtual void increase_score(int value) {};
    };
}

#endif //ROADFIGHTER_ENTITY_H
