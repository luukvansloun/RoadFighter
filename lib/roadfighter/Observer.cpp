//
// Created by luuk on 6-1-19.
//

#include "Observer.h"
#include "Subject.h"

Observer::Observer(std::shared_ptr<Subject> subj) {
    subject = subj;

    subject->attach(shared_from_this());
}

std::shared_ptr<Subject> Observer::getSubject() {
    return subject;
}
