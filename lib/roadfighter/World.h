//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <iostream>
#include <memory>
#include "PlayerCar.h"

namespace roadfighter {
    class World : public roadfighter::Entity {
    private:
        std::shared_ptr<roadfighter::Entity> playercar;

    public:
        World();

        virtual ~World();

        const std::shared_ptr<roadfighter::Entity> &getPlayercar() const;

        void setPlayercar(const std::shared_ptr<roadfighter::Entity> &playercar);

        void move_player_right();

        void move_player_left();
    };
}


#endif //ROADFIGHTER_WORLD_H
