//
// Created by luuk on 27-11-18.
//

#ifndef ROADFIGHTER_TRANSFORMATION_H
#define ROADFIGHTER_TRANSFORMATION_H

#include <iostream>
#include <memory>

class Transformation {

public:
    static std::shared_ptr<Transformation> getInstance();

//    std::pair<float, float> get_coordinates(std::pair<int, int> co, int x, int y);

    virtual ~Transformation();
private:
    static std::shared_ptr<Transformation> instance;

};


#endif //ROADFIGHTER_TRANSFORMATION_H
