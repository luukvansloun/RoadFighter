//
// Created by luuk on 6-1-19.
//

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
    Observer();

    void setSubject(std::shared_ptr<roadfighter::Entity> subj);

    virtual void update() {};

protected:
    std::shared_ptr<roadfighter::Entity> getSubject();
};


#endif //ROADFIGHTER_OBSERVER_H
