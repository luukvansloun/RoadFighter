//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_SFMLFACTORY_H
#define ROADFIGHTER_SFMLFACTORY_H

#include <iostream>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

namespace roadfighterSFML {

    class SFMLFactory {
    public:
        SFMLFactory(std::shared_ptr<sf::RenderWindow> window);

        virtual ~SFMLFactory();

    private:
        std::shared_ptr<sf::RenderWindow> window;
    };
}

#endif //ROADFIGHTER_SFMLFACTORY_H
