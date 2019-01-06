//
// Created by luuk on 6-1-19.
//

#ifndef ROADFIGHTER_OBSERVER_H
#define ROADFIGHTER_OBSERVER_H

#include <iostream>
#include <memory>
#include "Entity.h"

class Subject;

class Observer : public std::enable_shared_from_this<Observer> {
private:
    std::shared_ptr<Observer> obs;
    std::shared_ptr<roadfighter::Entity> subject;

public:
    Observer();

    void setSubject(std::shared_ptr<roadfighter::Entity> subj);

    std::shared_ptr<Observer> getObserver();

    virtual void update() {};

protected:
    std::shared_ptr<roadfighter::Entity> getSubject();
};


#endif //ROADFIGHTER_OBSERVER_H
