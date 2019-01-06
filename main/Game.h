//
// Created by luuk on 6-12-18.
//

#ifndef ROADFIGHTER_GAME_H
#define ROADFIGHTER_GAME_H

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <World.h>
#include <Observer.h>
#include <HighScore.h>

#include "json.hpp"
#include "Transformation.h"
#include "../roadfighterSFML/SFMLFactory.h"

class Game : public Observer {
public:
    Game();

    virtual ~Game();

    void setupBackground();

    void run();

    void setup_opponents();

    void add_entity(std::string type);

    void update_background();

    void finish_background();

    void end_of_game();

    void update() override;

private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::View view;
    std::shared_ptr<roadfighterSFML::SFMLFactory> sfml_factory;
    std::shared_ptr<roadfighter::World> world;
    sf::Texture bgTexture;
    sf::Sprite background;
    std::vector<nlohmann::json> game_objects;
    bool EOG = false;
    int score = 0;
    std::shared_ptr<roadfighter::HighScore> highscores;
};


#endif //ROADFIGHTER_GAME_H
