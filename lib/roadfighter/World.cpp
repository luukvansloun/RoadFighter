//
// Created by luuk on 5-12-18.
//

#include "World.h"

roadfighter::World::~World() {}

roadfighter::World::World() {}

void roadfighter::World::move_player_right() {
    float plus = 0.05;
    if(playercar->getX() + plus > float(0.025)) {
        std::cout << "CRASH" << std::endl;
    }
    else {
        playercar->setX(playercar->getX() + plus);
    }

    playercar->change_position();
}

void roadfighter::World::move_player_left() {
    float minus = 0.05;

    if(playercar->getX() - minus < float(-2.45)) {
        std::cout << "CRASH" << std::endl;
    }
    else {
        playercar->setX(playercar->getX() - minus);
    }

    playercar->change_position();
}

bool roadfighter::World::move_player_up() {
    float new_y = getPlayercar()->getY() + (getPlayercar()->getSpeed() * 0.000375);

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

const std::vector<std::shared_ptr<roadfighter::Entity>> &roadfighter::World::getOpponents() const {
    return opponents;
}

void roadfighter::World::add_entity(std::shared_ptr<roadfighter::Entity> entity) {
    this->entities.push_back(entity);
}

void roadfighter::World::add_opponent(std::shared_ptr<roadfighter::Entity> opponent) {
    this->opponents.push_back(opponent);
}

void roadfighter::World::update_entities() {
    auto it = this->entities.begin();

    while(it != this->entities.end()) {
        float y_inc = (getPlayercar()->getSpeed() - it->get()->getSpeed()) * 0.00075;
        if((it->get()->getY() - y_inc) >= 800) {
            it = this->entities.erase(it);
        }
        else {
            it->get()->setY(it->get()->getY() - y_inc);
            it->get()->change_position();
            ++it;
        }
    }
}

void roadfighter::World::update_opponents() {
    for(const auto& opponent : this->opponents) {
        float y_inc = (getPlayercar()->getSpeed() - opponent->getSpeed()) * 0.00075;

        opponent->setY(opponent->getY() - y_inc);
        opponent->change_position();
    }
}

void roadfighter::World::draw() {
    playercar->draw();

    for(const auto& entity : entities) {
        entity->draw();
    }
    for(const auto& opponent : opponents) {
        opponent->draw();
    }
}

bool roadfighter::World::detect_collision(std::shared_ptr<roadfighter::Entity> entity_one,
                                          std::shared_ptr<roadfighter::Entity> entity_two) {

    // Both entities with the y-coödinate plus it's height
    float one_y_height = entity_one->getY() + entity_one->getHeight();
    float two_y_height = entity_two->getY() + entity_two->getHeight();

    // Both entities with the x-coördinate plus it's width
    float one_x_width = entity_one->getX() + entity_one->getWidth();
    float two_x_width = entity_two->getX() + entity_two->getWidth();

    // Check if Y-axes cross
    if((entity_one->getY() >= entity_two->getY() and entity_one->getY() <= two_y_height) or
            (one_y_height >= entity_two->getY() and one_y_height <= two_y_height)) {
        // Check if X-axes cross
        if((entity_one->getX() >= entity_two->getX() and entity_one->getX() <= two_x_width) or
           (one_x_width >= entity_two->getX() and one_x_width <= two_x_width)) {
            // All axes cross, so there's collision
            return true;
        }
    }

    // No collision detected
    return false;
}



