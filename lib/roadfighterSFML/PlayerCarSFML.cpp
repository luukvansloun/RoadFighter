//
// Created by luuk on 5-12-18.
//

#include "PlayerCarSFML.h"

// PLAYERCAR SFML CLASS

roadfighterSFML::PlayerCarSFML::PlayerCarSFML() {}

roadfighterSFML::PlayerCarSFML::~PlayerCarSFML() {

}

void roadfighterSFML::PlayerCarSFML::setup_SFML() {

}


// ABSTRACT FACTORY CLASS

std::shared_ptr<roadfighterSFML::PlayerCarSFML> roadfighterSFML::PlayerCarSFML_Factory::create_entity() {
    return std::shared_ptr<roadfighterSFML::PlayerCarSFML>();
}
