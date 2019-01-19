//
// Created by luuk on 6-1-19.
//

#include "Observer.h"

std::shared_ptr<roadfighter::Entity> Observer::getSubject() {
    return subject;
}

void Observer::setSubject(std::shared_ptr<roadfighter::Entity> subj) {
    subject = subj;

    subj->attach(std::shared_ptr<Observer>(this, [] (Observer* ptr) {}));
}


