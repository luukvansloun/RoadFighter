//
// Created by luuk on 5-12-18.
//

#ifndef ROADFIGHTER_PLAYERCAR_H
#define ROADFIGHTER_PLAYERCAR_H

#include <iostream>
#include <memory>

#include <PlayerCarEntity.h>
#include <PlayerCarSFML.h>

class PlayerCarFactory {
public:
    std::pair<std::shared_ptr<roadfighter::PlayerCarEntity>, std::shared_ptr<roadfighterSFML::PlayerCarSFML>> create_playercar();
};


#endif //ROADFIGHTER_PLAYERCAR_H
