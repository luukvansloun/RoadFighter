//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_ENTITYFACTORY_H
#define ROADFIGHTER_ENTITYFACTORY_H

#include <iostream>
#include <memory>
#include "Entity.h"

class EntityFactory {
public:
    virtual std::shared_ptr<roadfighter::Entity> create_playercar() = 0;
    virtual std::shared_ptr<roadfighter::Entity> create_racingcar() = 0;
    virtual std::shared_ptr<roadfighter::Entity> create_truck() = 0;
    virtual std::shared_ptr<roadfighter::Entity> create_lorry() = 0;
    virtual std::shared_ptr<roadfighter::Entity> create_bullet() = 0;
};


#endif //ROADFIGHTER_ENTITYFACTORY_H
