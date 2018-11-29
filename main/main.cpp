#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Entity.h>
#include "Transformation.h"

// 1 second divided by FPS gives time/frame
double tick = 1.0 / 60.0;

int main() {

    std::shared_ptr<Entity> e;
    e->test_f();

    sf::RenderWindow window(sf::VideoMode(800, 600), "RoadFighter");

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
};