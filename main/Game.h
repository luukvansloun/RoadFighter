//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_GAME_H
#define ROADFIGHTER_GAME_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../roadfighterSFML/WorldSFML.h"

#include "../roadfighterSFML/SFMLFactory.h"

class Game {
public:
    Game();

    virtual ~Game();

    void run();

private:
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<roadfighterSFML::SFMLFactory> sfml_factory;
    std::shared_ptr<roadfighterSFML::WorldSFML> world;
};


#endif //ROADFIGHTER_GAME_H
