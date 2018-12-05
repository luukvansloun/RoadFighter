//
// Created by luuk on 5-12-18.
//

#include "PlayerCar.h"

std::pair<std::shared_ptr<roadfighter::PlayerCarEntity>,
        std::shared_ptr<roadfighterSFML::PlayerCarSFML>> PlayerCarFactory::create_playercar() {

    std::pair<std::shared_ptr<roadfighter::PlayerCarEntity>,
            std::shared_ptr<roadfighterSFML::PlayerCarSFML>> pc;

    // PlayerCar Entity Factory
    std::shared_ptr<roadfighter::PlayerCarEntity_Factory> EF = std::make_shared<roadfighter::PlayerCarEntity_Factory>();
    // PlayerCar Entity
    std::shared_ptr<roadfighter::PlayerCarEntity> PC_E = EF->create_entity();

    // PlayerCar SFML Factory
    std::shared_ptr<roadfighterSFML::PlayerCarSFML_Factory> SF = std::make_shared<roadfighterSFML::PlayerCarSFML_Factory>();
    // PlayerCar SFML
    std::shared_ptr<roadfighterSFML::PlayerCarSFML> PCS_E = SF->create_entity();

    pc = std::make_pair(PC_E, PCS_E);

    return pc;
}
