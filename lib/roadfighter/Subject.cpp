//
// Created by luuk on 6-1-19.
//

#include "Subject.h"
#include "Observer.h"

void Subject::attach(std::shared_ptr<Observer> obs) {
    observers.push_back(obs);
}

void Subject::increase_score(int value) {
    score += value;
}

int Subject::getScore() {
    return score;
}

void Subject::notify() {
    for(const auto& obs : observers) {
        obs->update();
    }
}
