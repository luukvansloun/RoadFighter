//
// Created by luuk on 6-1-19.
//

#ifndef ROADFIGHTER_SUBJECT_H
#define ROADFIGHTER_SUBJECT_H

#include <iostream>
#include <memory>
#include <vector>

class Observer;

class Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    int score;

public:
    void attach(std::shared_ptr<Observer> obs);

    void increase_score(int value);

    int getScore();

    void notify();
};


#endif //ROADFIGHTER_SUBJECT_H
