//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_WORLDSFML_H
#define ROADFIGHTER_WORLDSFML_H

#include <iostream>
#include <memory>
#include <Entity.h>
#include "PlayerCarSFML.h"

namespace roadfighterSFML {
    class WorldSFML : public roadfighter::Entity {
    public:
        const std::shared_ptr<roadfighter::Entity> getPlayercar() const;

        void setPlayercar(const std::shared_ptr<roadfighter::Entity> playercar);

    private:
        std::shared_ptr<roadfighter::Entity> playercar;
    };
}

#endif //ROADFIGHTER_WORLDSFML_H
