//
// Created by luuk on 6-12-18.
//

#include "RacingCarSFML_Factory.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::RacingCarSFML_Factory::create_racingcar() {
    return std::make_shared<roadfighterSFML::RacingCarSFML>();
}
