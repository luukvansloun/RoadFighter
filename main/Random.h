//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_RANDOM_H
#define ROADFIGHTER_RANDOM_H

#include <iostream>
#include <memory>
#include <ctime>

class Random {
public:
    static std::shared_ptr<Random> getInstance();

    float get_random_x();

    virtual ~Random();

private:
    static std::shared_ptr<Random> instance;

};


#endif //ROADFIGHTER_RANDOM_H
