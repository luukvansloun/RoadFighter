//
// Created by luuk on 5-12-18.
//

#include "RacingCar.h"

std::pair<std::shared_ptr<roadfighter::RacingCarEntity>,
        std::shared_ptr<roadfighterSFML::RacingCarSFML>> RacingCarFactory::create_racingcar(){

    std::pair<std::shared_ptr<roadfighter::RacingCarEntity>,
            std::shared_ptr<roadfighterSFML::RacingCarSFML>> rc;

    // RacingCar Entity Factory
    std::shared_ptr<roadfighter::RacingCarEntity_Factory> EF = std::make_shared<roadfighter::RacingCarEntity_Factory>();
    // RacingCar Entity
    std::shared_ptr<roadfighter::RacingCarEntity> RC_E = EF->create_entity();

    // RacingCar SFML Factory
    std::shared_ptr<roadfighterSFML::RacingCarSFML_Factory> SF = std::make_shared<roadfighterSFML::RacingCarSFML_Factory>();
    // RacingCar SFML
    std::shared_ptr<roadfighterSFML::RacingCarSFML> RCS_E = SF->create_entity();

    rc = std::make_pair(RC_E, RCS_E);

    return rc;
}