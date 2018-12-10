#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Transformation.h"
#include "Random.h"

#include "PlayerCar.h"
#include "Game.h"


int main() {

    auto game = std::make_shared<Game>();

    game->run();

//    // Create Player Car
//    auto playercar = PlayerCarFactory().create_playercar();
//
//    // Get Start Location for PC
//    std::pair<float, float> pc_co = Transformation::getInstance()->get_coordinates(std::make_pair(0, 0),
//                                      window.getView().getSize().x, window.getView().getSize().y);
//
//    playercar.first->setX(pc_co.first);
//    playercar.first->setY(pc_co.second);
//
//    playercar.second->setup_sfml("sprites/player_sprite.png", playercar.first->getX(), playercar.first->getY());

    return 0;
};