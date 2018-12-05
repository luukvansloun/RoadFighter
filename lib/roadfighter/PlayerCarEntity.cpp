//
// Created by luuk on 5-12-18.
//

#include "PlayerCarEntity.h"

// PLAYERCAR ENTITY CLASS

roadfighter::PlayerCarEntity::PlayerCarEntity() {}

roadfighter::PlayerCarEntity::~PlayerCarEntity() {

}

float roadfighter::PlayerCarEntity::getX() const {
    return x;
}

void roadfighter::PlayerCarEntity::setX(float x) {
    PlayerCarEntity::x = x;
}

float roadfighter::PlayerCarEntity::getY() const {
    return y;
}

void roadfighter::PlayerCarEntity::setY(float y) {
    PlayerCarEntity::y = y;
}


// ABSTRACT FACTORY CLASS

roadfighter::PlayerCarEntity_Factory::PlayerCarEntity_Factory() {}

std::shared_ptr<roadfighter::PlayerCarEntity> roadfighter::PlayerCarEntity_Factory::create_entity() {
    return std::make_shared<PlayerCarEntity>();
}




