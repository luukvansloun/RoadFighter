//
// Created by luuk on 6-12-18.
//

#include "WorldSFML.h"

const std::shared_ptr<roadfighter::Entity> roadfighterSFML::WorldSFML::getPlayercar() const {
    return playercar;
}

void roadfighterSFML::WorldSFML::setPlayercar(const std::shared_ptr<roadfighter::Entity> playercar) {
    WorldSFML::playercar = playercar;
}
