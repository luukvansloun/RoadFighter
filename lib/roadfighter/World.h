//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <iostream>
#include <memory>
#include <vector>
#include "PlayerCar.h"

namespace roadfighter {
    class World : public roadfighter::Entity {
    private:
        std::shared_ptr<roadfighter::Entity> playercar;
        std::vector<std::shared_ptr<roadfighter::Entity>> entities;
        std::vector<std::shared_ptr<roadfighter::Entity>> opponents;

    public:
        World();

        virtual ~World();

        const std::shared_ptr<roadfighter::Entity> &getPlayercar() const;

        void setPlayercar(const std::shared_ptr<roadfighter::Entity> &playercar);

        void move_player_right();

        void move_player_left();

        bool move_player_up();

        const std::vector<std::shared_ptr<Entity>> &getEntities() const;

        void add_entity(std::shared_ptr<roadfighter::Entity> entity);

        void add_opponent(std::shared_ptr<roadfighter::Entity> opponent);

        void update_entities();

        void update_opponents();

        const std::vector<std::shared_ptr<Entity>> &getOpponents() const;
    };
}


#endif //ROADFIGHTER_WORLD_H
