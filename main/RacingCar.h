//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_RACINGCAR_H
#define ROADFIGHTER_RACINGCAR_H


#include <iostream>
#include <memory>

#include <RacingCarEntity.h>
#include <RacingCarSFML.h>

class RacingCarFactory {
public:
    std::pair<std::shared_ptr<roadfighter::RacingCarEntity>,
            std::shared_ptr<roadfighterSFML::RacingCarSFML>> create_racingcar();
};


#endif //ROADFIGHTER_RACINGCAR_H
