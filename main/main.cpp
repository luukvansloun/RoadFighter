#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Singletons/Transformation.h"
#include "Singletons/Random.h"

#include "PlayerCar.h"
#include "Game.h"


int main() {

    // Set the seed for the random number generator
    srand(time(NULL));

    // Create game
    auto game = std::make_shared<Game>();

    // Start the game loop
    game->run();

    return 0;
};