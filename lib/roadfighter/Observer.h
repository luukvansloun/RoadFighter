//
// Created by luuk on 6-1-19.
//

#ifndef ROADFIGHTER_OBSERVER_H
#define ROADFIGHTER_OBSERVER_H

#include <iostream>
#include <memory>

class Subject;

class Observer : std::enable_shared_from_this<Observer> {
private:
    std::shared_ptr<Subject> subject;

public:
    Observer(std::shared_ptr<Subject> subj);

    virtual void update() = 0;

protected:
    std::shared_ptr<Subject> getSubject();
};


#endif //ROADFIGHTER_OBSERVER_H
