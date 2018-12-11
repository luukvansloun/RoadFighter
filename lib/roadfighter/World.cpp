//
// Created by luuk on 5-12-18.
//

#include "World.h"

roadfighter::World::~World() {}

roadfighter::World::World() {}

void roadfighter::World::move_player_right() {
    float plus = 0.025;
    if(playercar->getX() + plus > float(0.025)) {
        std::cout << "CRASH" << std::endl;
    }
    else {
        playercar->setX(playercar->getX() + plus);
    }
}

void roadfighter::World::move_player_left() {
    float minus = 0.025;

    if(playercar->getX() - minus < float(-2.45)) {
        std::cout << "CRASH" << std::endl;
    }
    else {
        playercar->setX(playercar->getX() - minus);
    }
}

bool roadfighter::World::move_player_up() {
    float new_y = getPlayercar()->getY() + (getPlayercar()->getSpeed() * 0.00075);

    if(new_y > 4) {
        return true;
    }
    else {
        playercar->setY(new_y);
        return false;
    }
}

const std::shared_ptr<roadfighter::Entity> &roadfighter::World::getPlayercar() const {
    return playercar;
}

void roadfighter::World::setPlayercar(const std::shared_ptr<roadfighter::Entity> &playercar) {
    World::playercar = playercar;
}

const std::vector<std::shared_ptr<roadfighter::Entity>> &roadfighter::World::getEntities() const {
    return entities;
}

void roadfighter::World::add_entity(std::shared_ptr<roadfighter::Entity> entity) {
    this->entities.push_back(entity);
}

void roadfighter::World::update_entities() {
    for(const auto& entity : this->entities) {
        float y_inc = (getPlayercar()->getSpeed() - entity->getSpeed()) * 0.00075;

        entity->setY(entity->getY() - y_inc);
    }
}


