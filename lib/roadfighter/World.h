//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <iostream>
#include <memory>
#include <vector>
#include "PlayerCar.h"
#include "../../main/Singletons/Random.h"

namespace roadfighter {
    class World : public roadfighter::Entity {
    private:
        std::shared_ptr<roadfighter::Entity> playercar;
        std::vector<std::shared_ptr<roadfighter::Entity>> entities;
        std::vector<std::shared_ptr<roadfighter::Entity>> opponents;
        float left_border = -2.45;
        float right_border = 0.025;

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

        void draw() override;

        bool detect_collision(std::shared_ptr<roadfighter::Entity> entity_one,
                              std::shared_ptr<roadfighter::Entity> entity_two);

        bool check_left(std::shared_ptr<roadfighter::Entity> opponent,
                        std::shared_ptr<roadfighter::Entity> entity);

        bool check_right(std::shared_ptr<roadfighter::Entity> opponent,
                         std::shared_ptr<roadfighter::Entity> entity);
    };
}


#endif //ROADFIGHTER_WORLD_H
