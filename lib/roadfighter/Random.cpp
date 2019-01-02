//
// Created by luuk on 10-12-18.
//

#include "Random.h"

Random::Random() {};

float Random::get_random_x() {
    auto leftmost_x = float(-2.45);
    float rightmost_x = 0.025;

    float random = ((float) rand()) / (float) RAND_MAX;
    float delta_x = rightmost_x - leftmost_x;
    float rand_x = random * delta_x;

    return leftmost_x + rand_x;

}

bool Random::get_direction() {
    // Chances to go left or right are 50%
    return (rand() % 100) < 50;
}
