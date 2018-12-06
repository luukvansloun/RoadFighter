//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_RACINGCARSFML_FACTORY_H
#define ROADFIGHTER_RACINGCARSFML_FACTORY_H

#include <iostream>
#include <memory>
#include <EntityFactory.h>
#include "RacingCarSFML.h"

namespace roadfighterSFML {
    class RacingCarSFML_Factory : public EntityFactory {
    public:
        std::shared_ptr<roadfighter::Entity> create_racingcar() override;
    };
}

#endif //ROADFIGHTER_RACINGCARSFML_FACTORY_H
