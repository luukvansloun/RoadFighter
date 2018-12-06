//
// Created by luuk on 6-12-18.
//

#include "SFMLFactory.h"

roadfighterSFML::SFMLFactory::SFMLFactory(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

roadfighterSFML::SFMLFactory::~SFMLFactory() {}
