//
// Created by luuk on 6-12-18.
//

#include "PlayerCarSFML_Factory.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::PlayerCarSFML_Factory::create_playercar(){
    return std::make_shared<roadfighterSFML::PlayerCarSFML>();
}