//
// Created by luuk on 5-12-18.
//

#include "RacingCarEntity.h"

// RACINGCAR ENTITY CLASS

roadfighter::RacingCarEntity::RacingCarEntity() {}

roadfighter::RacingCarEntity::~RacingCarEntity() {

}

float roadfighter::RacingCarEntity::getX() const {
    return x;
}

void roadfighter::RacingCarEntity::setX(float x) {
    RacingCarEntity::x = x;
}

float roadfighter::RacingCarEntity::getY() const {
    return y;
}

void roadfighter::RacingCarEntity::setY(float y) {
    RacingCarEntity::y = y;
}


// ABSTRACT FACTORY CLASS

roadfighter::RacingCarEntity_Factory::RacingCarEntity_Factory(){}

std::shared_ptr<roadfighter::RacingCarEntity> roadfighter::RacingCarEntity_Factory::create_entity() {
    return std::make_shared<RacingCarEntity>();
}