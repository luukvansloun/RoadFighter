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
        if((it->get()->getY() - y_inc) <= -5) {
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

        if(!this->entities.empty()) {
            for(const auto& entity : this->entities) {
                if(detect_collision(opponent, entity)) {
                    std::cout << "Collision" << std::endl;
                    std::cout << "Opponent: " << opponent->getX() << " - " << opponent->getY() << std::endl;
                    bool collision = true;
                    while(collision) {
                        bool left_free = check_left(opponent, entity);
                        bool right_free = check_right(opponent, entity);

                        // See if collision will happen to both sides
                        if(!left_free and !right_free){
                            collision = true;
                        }
                        else {
                            collision = false;
                        }

                        // If both options are available
                        if(left_free and right_free) {
                            // Let Random decide a new position (false == left, right == true)
                            if(Random::get_instance().get_direction()) {
                                opponent->setX(opponent->getX() - (opponent->getWidth() * 0.01) - 0.10);
                            }
                            else {
                                opponent->setX(opponent->getX() + (opponent->getWidth() * 0.01) + 0.10);
                            }
                        }
                        else if(!left_free and !right_free) {
                            // See what side has the most room to minimise collision chances
                            if((opponent->getX() - this->left_border) >= (this->right_border - opponent->getX())) {
                                opponent->setX(opponent->getX() - (opponent->getWidth() * 0.01) - 0.10);
                            }
                            else {
                                opponent->setX(opponent->getX() + (opponent->getWidth() * 0.01) + 0.10);
                            }
                        }
                        else if(right_free) {
                            opponent->setX(opponent->getX() - (opponent->getWidth() * 0.01) - 0.10);
                        }
                        else if(left_free) {
                            opponent->setX(opponent->getX() + (opponent->getWidth() * 0.01) + 0.10);
                        }

                    }
                    std::cout << "Opponent: " << opponent->getX() << " - " << opponent->getY() << std::endl;
                }
            }
        }
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
    float one_y_height = entity_one->getY() + (entity_one->getHeight() * 0.01);
    float two_y_height = entity_two->getY() + (entity_two->getHeight() * 0.01);

    // Both entities with the x-coördinate plus it's width
    float one_x_width = entity_one->getX() + (entity_one->getWidth() * 0.01);
    float two_x_width = entity_two->getX() + (entity_two->getWidth() * 0.01);

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

bool roadfighter::World::check_left(std::shared_ptr<roadfighter::Entity> opponent,
        std::shared_ptr<roadfighter::Entity> entity) {
    bool world_free = false;
    bool no_collision = true;

    // Check if there's enough space to move into without hitting the side of the road
    if(opponent->getX() - (opponent->getWidth() + 0.10) > this->left_border) {
        world_free = true;
    }

    // Create temp opponent to check if new X coördinate causes collision with another entity
    auto tempCar = opponent;
    float new_x_co = tempCar->getX() - (tempCar->getWidth() * 0.01) - 0.10;
    tempCar->setX(new_x_co);

    // Check for collision if moved to the left
    for(const auto& ent : this->entities) {
        if(detect_collision(tempCar, ent)) {
            if(ent != entity) {
                no_collision = false;
            }
        }
    }

    return (world_free and no_collision);
}

bool roadfighter::World::check_right(std::shared_ptr<roadfighter::Entity> opponent,
                                     std::shared_ptr<roadfighter::Entity> entity) {
    bool world_free = false;
    bool no_collision = true;

    // Check if there's enough space to move into without hitting the side of the road
    if(opponent->getX() + (opponent->getWidth() + 0.10) > this->right_border) {
        world_free = true;
    }

    // Create temp opponent to check if new X coördinate causes collision with another entity
    auto tempCar = opponent;
    float new_x_co = tempCar->getX() + (tempCar->getWidth() * 0.01) + 0.10;
    tempCar->setX(new_x_co);

    // Check for collision if moved to the left
    for(const auto& ent : this->entities) {
        if(detect_collision(tempCar, ent)) {
            if(ent != entity) {
                no_collision = false;
            }
        }
    }

    return (world_free and no_collision);
}



