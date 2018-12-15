//
// Created by luuk on 10-12-18.
//

#ifndef ROADFIGHTER_RANDOM_H
#define ROADFIGHTER_RANDOM_H

#include <iostream>
#include <memory>
#include <ctime>

class Random {
private:
    Random();

public:
    Random(Random const&) = delete;
    void operator=(Random const&) = delete;

    static Random& get_instance() {
        static Random instance;
        return instance;
    }

    float get_random_x();

};


#endif //ROADFIGHTER_RANDOM_H
