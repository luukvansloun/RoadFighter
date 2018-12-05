//
// Created by luuk on 5-12-18.
//

#include "RacingCarSFML.h"

// RACINGCAR SFML CLASS

roadfighterSFML::RacingCarSFML::RacingCarSFML() {}

roadfighterSFML::RacingCarSFML::~RacingCarSFML() {

}

void roadfighterSFML::RacingCarSFML::setup_SFML() {

}


// ABSTRACT FACTORY CLASS

std::shared_ptr<roadfighterSFML::RacingCarSFML> roadfighterSFML::RacingCarSFML_Factory::create_entity() {
    return std::shared_ptr<roadfighterSFML::RacingCarSFML>();
}