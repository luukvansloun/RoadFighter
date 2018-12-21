//
// Created by luuk on 5-12-18.
//

#include "World.h"

roadfighter::World::~World() {}

roadfighter::World::World() {}

void roadfighter::World::move_player_right() {
    float plus = 0.0375;
    if(playercar->getX() + plus > float(0.025)) {
        playercar->setCrashed(true);
        playercar->setSpeed(0);
    }
    else {
        playercar->setX(playercar->getX() + plus);
    }

    playercar->change_position();
}

void roadfighter::World::move_player_left() {
    float minus = 0.0375;

    if(playercar->getX() - minus < float(-2.45)) {
        playercar->setCrashed(true);
        playercar->setSpeed(0);
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

void roadfighter::World::update_all() {
    auto all_entities = this->entities;
    all_entities.insert(all_entities.begin(), this->opponents.begin(), this->opponents.end());
    all_entities.push_back(this->playercar);

    for(const auto& entity_one : all_entities) {
        for(const auto& entity_two : all_entities) {
            if(entity_one != entity_two) {
                if(!entity_one->getCrash().first and !entity_two->getCrash().first) {
                    if(detect_collision(entity_one, entity_two)) {
                        if(entity_one->get_type() != "Bullet" and entity_two->get_type() != "Bullet") {
                            if (entity_one->getX() >= (entity_two->getX() + (entity_two->getWidth() * 0.005))) {
                                entity_one->setCrash(std::make_pair(true, "right"));
                                entity_two->setCrash(std::make_pair(true, "left"));
                            }
                            else {
                                entity_one->setCrash(std::make_pair(true, "left"));

                                entity_two->setCrash(std::make_pair(true, "right"));
                            }
                        }
                        else {
                            if(entity_one->get_type() == "Bullet") {
                                if(entity_two->get_type() != "PlayerCar") {
                                    entity_two->setHealth(entity_two->getHealth() - 1);
                                    entity_two->setCrash(std::make_pair(true, "center"));
                                }
                            }
                            else {
                                if(entity_one->get_type() != "PlayerCar") {
                                    entity_one->setHealth(entity_one->getHealth() - 1);
                                    entity_one->setCrash(std::make_pair(true, "center"));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Check Player
    playercar->update(playercar->isCrashed());
    if(this->playercar->getCrash().first) {
        this->crashing(playercar);
    }

    // Check Opponents

    auto opp = this->opponents.begin();

    while(opp != this->opponents.end()) {
        opp->get()->update(opp->get()->isCrashed());
        if(opp->get()->isCrashed()) {
            if(opp->get()->explosion_finished()) {
                opp = this->opponents.erase(opp);
            }
            else {
                ++opp;
            }
        }
        else if(opp->get()->getCrash().first) {
            this->crashing(*opp);
            ++opp;
        }
        else {
            if(opp->get()->getSpeed() < 200 and !opp->get()->isCrashed()) {
                opp->get()->setSpeed(opp->get()->getSpeed() + 10);
            }
            else {
                float y_inc = float(getPlayercar()->getSpeed() - opp->get()->getSpeed()) * 0.00075f;
                if((opp->get()->getY() - y_inc) <= -3) {
                    opp = this->opponents.erase(opp);
                }
                else {
                    opp->get()->setY(opp->get()->getY() - y_inc);
                    opp->get()->change_position();
                    ++opp;
                }
            }
        }
    }

    auto entity = this->entities.begin();

    while(entity != this->entities.end()) {
        if(entity->get()->get_type() != "Bullet") {
            entity->get()->update(entity->get()->isCrashed());
            if(entity->get()->isCrashed()) {
                if(entity->get()->explosion_finished()) {
                    entity = this->entities.erase(entity);
                }
                else {
                    ++entity;
                }
            }
            else if(entity->get()->getCrash().first) {
                this->crashing(*entity);
                ++entity;
            }
            else {
                if(entity->get()->getSpeed() < 200 and !entity->get()->isCrashed()) {
                    entity->get()->setSpeed(entity->get()->getSpeed() + 10);
                }
                else {
                    float y_inc = float(getPlayercar()->getSpeed() - entity->get()->getSpeed()) * 0.00075f;
                    if((entity->get()->getY() - y_inc) <= -3) {
                        entity = this->entities.erase(entity);
                    }
                    else {
                        entity->get()->setY(entity->get()->getY() - y_inc);
                        entity->get()->change_position();
                        ++entity;
                    }
                }
            }
        }
        else {
            float y_inc = float(getPlayercar()->getSpeed() - entity->get()->getSpeed()) * 0.00075f;
            if((entity->get()->getY() - y_inc) >= 3) {
                entity = this->entities.erase(entity);
            }
            else {
                entity->get()->setY(entity->get()->getY() - y_inc);
                entity->get()->change_position();
                ++entity;
            }

        }
    }
}

void roadfighter::World::crashing(std::shared_ptr<roadfighter::Entity> entity) {
    if(entity->getCrash().first and entity->getSpeed() > 0) {
        if(entity->getCrash().second == "right") {
            float new_x = entity->getX() + 0.05;
            if(new_x >= this->right_border) {
                entity->setSpeed(0);
                entity->setCrash(std::make_pair(false, ""));
                entity->setCrashed(true);
            }
            else if(entity->getHealth() == 0) {
                entity->setSpeed(0);
                entity->setCrash(std::make_pair(false, ""));
                entity->setCrashed(true);
            }
            else {
                entity->setX(new_x);
                entity->setSpeed(entity->getSpeed() - 25);
                entity->change_position();
            }
        }
        else if(entity->getCrash().second == "left") {
            float new_x = entity->getX() - 0.05;
            if(new_x <= this->left_border) {
                entity->setSpeed(0);
                entity->setCrash(std::make_pair(false, ""));
                entity->setCrashed(true);
            }
            else if(entity->getHealth() == 0) {
                entity->setSpeed(0);
                entity->setCrash(std::make_pair(false, ""));
                entity->setCrashed(true);
            }
            else {
                entity->setX(new_x);
                entity->setSpeed(entity->getSpeed() - 25);
                entity->change_position();
            }
        }
        // Collision with a bullet
        else if(entity->getCrash().second == "center") {
            if(entity->getHealth() == 0) {
                entity->setSpeed(0);
                entity->setCrash(std::make_pair(false, ""));
                entity->setCrashed(true);
            }
            entity->setSpeed(entity->getSpeed() - 25);
            entity->change_position();
        }
    }
    else {
        // TODO Animation for explosion
        entity->setCrash(std::make_pair(false, ""));
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
    float one_y_height = entity_one->getY() + (entity_one->getHeight() * 0.01);
    float two_y_height = entity_two->getY() + (entity_two->getHeight() * 0.01);

    // Both entities with the x-coördinate plus it's width
    float one_x_width = entity_one->getX() + (entity_one->getWidth() * 0.01);
    float two_x_width = entity_two->getX() + (entity_two->getWidth() * 0.01);

    if(!entity_one->isCrashed() and !entity_two->isCrashed()) {
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
    }
    // No collision detected
    return false;
}