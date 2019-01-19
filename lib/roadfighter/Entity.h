/**
 * @file Entity.h
 *
 * @brief Header file for Entity class
 *
 * @class roadfighter::Entity
 *
 * @brief This Class contains all the functionalities of the Entity object.
 *
 * @authors Luuk van Sloun
 */


#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include <iostream>
#include <memory>

class Observer;

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class Entity {
    public:
        /**
         * @struct crash_struct
         * @brief This Struct contains the three elements needed to define a crash
         * @param bool crash;
         * @param std::string direction
         * @param std::shared_ptr<roadfighter::Entity> type
         */
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
        /**
        * @fn float getX() const
        * @brief Returns the Entity's x-coördinate
        * @return float
        */
        float getX() const;

        /**
        * @fn void setX(float x)
        * @param float x
        * @brief Sets the Entity's x-coördinate
        */
        void setX(float x);

        /**
        * @fn float getY() const
        * @brief Returns the Entity's y-coördinate
        * @return float
        */
        float getY() const;

        /**
        * @fn void setY(float y)
        * @param float y
        * @brief Sets the Entity's y-coördinate
        */
        void setY(float y);

        /**
        * @fn const crash_struct &getCrash() const
        * @brief Returns the Entity's crash struct
        * @return const crash_struct
        */
        const crash_struct &getCrash() const;

        /**
        * @fn void setCrash(const crash_struct &crash)
        * @param const crash_struct &crash
        * @brief Sets the Entity's crash struct
        */
        void setCrash(const crash_struct &crash);

        /**
        * @fn bool isCrashed() const
        * @brief Returns True if the Entity has crashed
        * @return bool
        */
        bool isCrashed() const;

        /**
        * @fn void setCrashed(bool crashed)
        * @param bool crashed
        * @brief Sets the Entity's crashed boolean
        */
        void setCrashed(bool crashed);

        /**
         * @fn virtual std::string get_type()
         * @brief Declaration of the get_type function (Only used in derived Entities)
         */
        virtual std::string get_type() {return "";};

        /**
         * @fn virtual void change_position()
         * @brief Declaration of the change_position function (Only used in derived SFML objects)
         */
        virtual void change_position() {};

        /**
         * @fn virtual void draw()
         * @brief Declaration of the draw function (Only used in derived SFML objects)
         */
        virtual void draw() {};

        /**
         * @fn virtual double getSpeed() const
         * @brief Declaration of the getSpeed function (Only used in derived Entities)
         */
        virtual double getSpeed() const {return 0;};

        /**
         * @fn virtual void setSpeed(double speed)
         * @brief Declaration of the setSpeed function (Only used in derived Entities)
         */
        virtual void setSpeed(double speed) {};

        /**
         * @fn virtual int getMax_speed() const
         * @brief Declaration of the getMax_speed function (Only used in derived Entity Player Car)
         */
        virtual int getMax_speed() const {return 0;};

        /**
         * @fn virtual double getDistance() const
         * @brief Declaration of the getDistance function (Only used in derived Entities)
         */
        virtual double getDistance() const {return 0;};

        /**
         * @fn virtual void update_distance(double distance)
         * @brief Declaration of the update_distance function (Only used in derived Entities)
         */
        virtual void update_distance(double distance) {};

        /**
         * @fn virtual int getHealth() const
         * @brief Declaration of the getHealth function (Only used in derived Entities)
         */
        virtual int getHealth() const {return 0;};

        /**
         * @fn virtual void setHealth(int health)
         * @brief Declaration of the setHealth function (Only used in derived Entities)
         */
        virtual void setHealth(int health) {};

        /**
         * @fn virtual void decrease_speed(int val)
         * @brief Declaration of the decrease_speed function (Only used in derived Entities)
         */
        virtual void decrease_speed(int val) {};

        /**
         * @fn virtual int getFuel() const
         * @brief Declaration of the getFuel function (Only used in derived Entity Player Car)
         */
        virtual int getFuel() const {return 0;};

        /**
         * @fn virtual void setFuel(int fuel)
         * @brief Declaration of the setFuel function (Only used in derived Entity Player Car)
         */
        virtual void setFuel(int fuel) {};

        /**
         * @fn virtual float getWidth() const
         * @brief Declaration of the getHeight function (Only used in derived SFML objects)
         */
        virtual float getWidth() const {return 0;};

        /**
         * @fn virtual float getHeight()
         * @brief Declaration of the getHeight function (Only used in derived SFML objects)
         */
        virtual float getHeight() const {return 0;};

        /**
         * @fn virtual void update(bool crashed)
         * @brief Declaration of the update function (Only used in derived Entities)
         */
        virtual void update(bool crashed) {};

        /**
         * @fn virtual bool explosion_finished()
         * @brief Declaration of the explosion_finished function (Only used in derived Entities)
         */
        virtual bool explosion_finished() {return false;};

        /**
         * @fn virtual bool isShoot() const
         * @brief Declaration of the isShoot function (Only used in derived Entity Player Car)
         */
        virtual bool isShoot() const {return false;};

        /**
         * @fn virtual void setShoot(bool shoot)
         * @brief Declaration of the setShoot function (Only used in derived Entity Player Car)
         */
        virtual void setShoot(bool shoot) {};

        /**
         * @fn virtual int getBullets() const
         * @brief Declaration of the getBullets function (Only used in derived Entity Player Car)
         */
        virtual int getBullets() const {return 0;};

        /**
         * @fn virtual void setBullets(int bullets)
         * @brief Declaration of the setBullets function (Only used in derived Entity Player Car)
         */
        virtual void setBullets(int bullets) {};

        /**
         * @fn virtual void attach(const std::shared_ptr<Observer> obs)
         * @brief Declaration of the attach function (Only used in derived Entity Player Car)
         */
        virtual void attach(const std::shared_ptr<Observer> obs) {};

        /**
         * @fn virtual void update()
         * @brief Declaration of the update function (Only used in derived Entities)
         */
        virtual void update() {};

        /**
         * @fn virtual double getScore()
         * @brief Declaration of the getScore function (Only used in derived Entity Player Car)
         */
        virtual double getScore() {return 0;};

        /**
         * @fn virtual void increase_score(double value)
         * @brief Declaration of the increase_score function (Only used in derived Entity Player Car)
         */
        virtual void increase_score(double value) {};
    };
}

#endif //ROADFIGHTER_ENTITY_H
