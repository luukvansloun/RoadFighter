#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Transformation.h"

#include "PlayerCar.h"

// 1 second divided by FPS gives time/frame
double tick = 1.0 / 60.0;

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "RoadFighter");

//    Transformation how_to
//    std::pair<float, float> co = Transformation::getInstance()->get_coordinates(std::make_pair(0.0, -2),
//                                      window.getView().getSize().x, window.getView().getSize().y);

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