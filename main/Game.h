/**
 * @file Game.h
 *
 * @brief Header file for Game class
 *
 * @class Game
 *
 * @brief This Class contains all the functionalities to run the Game.
 *
 * @authors Luuk van Sloun
 */

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
    /**
    * @fn Game()
    * @brief Constructor for the Game Class
    * @post New Game object has been created
    */
    Game();

    /**
    * @fn void setupBackground();
    * @brief Provides the setup for the Game Background
    */
    void setupBackground();

    /**
    * @fn void run();
    * @brief Contains partial setup and loop
    */
    void run();

    /**
    * @fn void setup_opponents();
    * @brief Provides the setup for the opponent racing cars
    */
    void setup_opponents();

    /**
    * @fn void add_entity(std::string type);
    * @param std::string type
    * @brief Adds an entity to the Game World
    */
    void add_entity(std::string type);

    /**
    * @fn void update_background();
    * @brief Moves the Background according to the Player's speed
    */
    void update_background();

    /**
    * @fn void finish_background();
    * @brief Changes the Background to the finishing Background
    */
    void finish_background();

    /**
    * @fn bool end_of_game();
    * @brief  Returns True if the Game has reached it's end
    * @return bool
    */
    bool end_of_game();

    /**
    * @fn void update() override;
    * @brief Updates the score using the Observer Pattern
    */
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
    double score = 0;
    std::shared_ptr<roadfighter::HighScore> highscores;
};


#endif //ROADFIGHTER_GAME_H
