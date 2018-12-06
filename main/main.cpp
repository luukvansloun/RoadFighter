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

    // Create Player Car
    auto playercar = PlayerCarFactory().create_playercar();

    // Get Start Location for PC
    std::pair<float, float> pc_co = Transformation::getInstance()->get_coordinates(std::make_pair(0, 0),
                                      window.getView().getSize().x, window.getView().getSize().y);

    playercar.first->setX(pc_co.first);
    playercar.first->setY(pc_co.second);

    playercar.second->setup_sfml("sprites/player_sprite.png", playercar.first->getX(), playercar.first->getY());

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                playercar.first->setX(playercar.first->getX() + 3);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                playercar.first->setX(playercar.first->getX() - 3);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if(playercar.first->getSpeed() < playercar.first->getMax_speed()) {
                    playercar.first->setSpeed(playercar.first->getSpeed() + 1);
                }
                std::cout << playercar.first->getSpeed() << std::endl;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if(playercar.first->getSpeed() > 0) {
                    playercar.first->setSpeed(playercar.first->getSpeed() - 1);
                }
                std::cout << playercar.first->getSpeed() << std::endl;
            }
        }


        playercar.second->setup_sfml("sprites/player_sprite.png", playercar.first->getX(), playercar.first->getY());

        window.clear(sf::Color::Black);
        window.draw(playercar.second->getSprite());
        window.display();
    }

    return 0;
};