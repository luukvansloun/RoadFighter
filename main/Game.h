//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_GAME_H
#define ROADFIGHTER_GAME_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <World.h>

#include "Transformation.h"
#include "../roadfighterSFML/SFMLFactory.h"

class Game {
public:
    Game();

    virtual ~Game();

    void setupBackground();

    void run();

private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::View view;
    std::shared_ptr<roadfighterSFML::SFMLFactory> sfml_factory;
    std::shared_ptr<roadfighter::World> world;
    sf::Texture bgTexture;
    sf::Sprite background;
};


#endif //ROADFIGHTER_GAME_H
