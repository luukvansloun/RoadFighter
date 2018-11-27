//
// Created by luuk on 27-11-18.
//

#ifndef ROADFIGHTER_TRANSFORMATION_H
#define ROADFIGHTER_TRANSFORMATION_H

#include <iostream>
#include <memory>


class Transformation {
protected:
    Transformation();

public:
    virtual ~Transformation();

    static Transformation* Instance();

private:
    static Transformation* transformation;
};


#endif //ROADFIGHTER_TRANSFORMATION_H
