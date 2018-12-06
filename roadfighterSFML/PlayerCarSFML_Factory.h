//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_PLAYERCARSFML_FACTORY_H
#define ROADFIGHTER_PLAYERCARSFML_FACTORY_H

#include <iostream>
#include <memory>
#include <EntityFactory.h>
#include "PlayerCarSFML.h"

namespace roadfighterSFML {
    class PlayerCarSFML_Factory : public EntityFactory {
    public:
        std::shared_ptr<roadfighter::Entity> create_playercar() override;
    };
}

#endif //ROADFIGHTER_PLAYERCARSFML_FACTORY_H
