//
// Created by luuk on 6-12-18.
//

#include "SFMLFactory.h"

// Constructor & Destructor
roadfighterSFML::SFMLFactory::SFMLFactory(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

roadfighterSFML::SFMLFactory::~SFMLFactory() {}

// Create Entity Functions

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::create_playercar() {
    return std::make_shared<roadfighterSFML::PlayerCarSFML>(window);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::create_racingcar() {
    return std::make_shared<roadfighterSFML::RacingCarSFML>(window);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::create_truck() {
    return std::make_shared<roadfighterSFML::TruckSFML>(window);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::create_lorry() {
    return std::make_shared<roadfighterSFML::LorrySFML>(window);
}