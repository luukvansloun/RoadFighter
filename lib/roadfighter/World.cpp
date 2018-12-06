//
// Created by luuk on 5-12-18.
//

#include "World.h"

roadfighter::World::~World() {}

roadfighter::World::World() {}



void roadfighter::World::move_player_right() {
    float plus = 0.05;
    playercar->setX(playercar->getX() + plus);
}

void roadfighter::World::move_player_left() {
    float minus = 0.05;
    playercar->setX(playercar->getX() - minus);
}

const std::shared_ptr<roadfighter::Entity> &roadfighter::World::getPlayercar() const {
    return playercar;
}

void roadfighter::World::setPlayercar(const std::shared_ptr<roadfighter::Entity> &playercar) {
    World::playercar = playercar;
}
