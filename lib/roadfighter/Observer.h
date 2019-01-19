/**
 * @file Observer.h
 *
 * @brief Header file for Observer class
 *
 * @class Observer
 *
 * @brief This Class contains all the functionalities of the Observer.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_OBSERVER_H
#define ROADFIGHTER_OBSERVER_H

#include <iostream>
#include <memory>
#include "Entity.h"

class Subject;

class Observer {
private:
    std::shared_ptr<roadfighter::Entity> subject;

public:
    /**
    * @fn Observer()
    * @brief Constructor for the Observer Class
    * @post New Observer object has been created
    */
    Observer();

    /**
    * @fn void setSubject(std::shared_ptr<roadfighter::Entity> subj)
    * @param std::shared_ptr<roadfighter::Entity> subj
    * @brief Sets the Subject to which the Observer is connected
    */
    void setSubject(std::shared_ptr<roadfighter::Entity> subj);

    /**
    * @fn virtual void update()
    * @brief Declaration of the update function which updates the score according to the Observer pattern (Only used in derived Observers)
    */
    virtual void update() {};

protected:
    std::shared_ptr<roadfighter::Entity> getSubject();
};


#endif //ROADFIGHTER_OBSERVER_H
