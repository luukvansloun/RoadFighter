//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_SFMLFACTORY_H
#define ROADFIGHTER_SFMLFACTORY_H

#include <iostream>
#include <memory>

#include <EntityFactory.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include "PlayerCarSFML.h"
#include "RacingCarSFML.h"

namespace roadfighterSFML {

    class SFMLFactory : public EntityFactory {
    public:
        SFMLFactory(std::shared_ptr<sf::RenderWindow> window);

        virtual ~SFMLFactory();

        std::shared_ptr<roadfighter::Entity> create_playercar() override;

        std::shared_ptr<roadfighter::Entity> create_racingcar() override;

    private:
        std::shared_ptr<sf::RenderWindow> window;
    };
}

#endif //ROADFIGHTER_SFMLFACTORY_H
