/**
 * @file SFMLFactory.h
 *
 * @brief Header file for SFMLFactory class
 *
 * @class roadfighterSFML::SFMLFactory
 *
 * @brief This Class contains the functions for creating SFML objects.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_SFMLFACTORY_H
#define ROADFIGHTER_SFMLFACTORY_H

#include <iostream>
#include <memory>

#include <EntityFactory.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include "PlayerCarSFML.h"
#include "RacingCarSFML.h"
#include "TruckSFML.h"
#include "LorrySFML.h"
#include "BulletSFML.h"

namespace roadfighterSFML {

class SFMLFactory : public roadfighter::EntityFactory {
    public:
        /**
        * @fn SFMLFactory(std::shared_ptr<sf::RenderWindow> window)
        * @param std::shared_ptr<sf::RenderWindow> window
        * @brief Constructor for the SFMLFactory Class
        * @post New SFMLFactory object has been created
        */
        SFMLFactory(std::shared_ptr<sf::RenderWindow> window);

        /**
        * @fn ~SFMLFactory()
        * @brief Constructor for the SFMLFactory Class
        * @post SFMLFactory object has been destroyed
        */
        virtual ~SFMLFactory();

        /**
        * @fn std::shared_ptr<roadfighter::Entity> create_playercar()
        * @brief Creates a Player Car object
        * @return std::shared_ptr<roadfighter::Entity>
        */
        std::shared_ptr<roadfighter::Entity> create_playercar() override;

        /**
        * @fn std::shared_ptr<roadfighter::Entity> create_racingcar()
        * @brief Creates a Racing Car object
        * @return std::shared_ptr<roadfighter::Entity>
        */
        std::shared_ptr<roadfighter::Entity> create_racingcar() override;

        /**
        * @fn std::shared_ptr<roadfighter::Entity> create_truck()
        * @brief Creates a Truck object
        * @return std::shared_ptr<roadfighter::Entity>
        */
        std::shared_ptr<roadfighter::Entity> create_truck() override;

        /**
        * @fn std::shared_ptr<roadfighter::Entity> create_lorry()
        * @brief Creates a Lorry object
        * @return std::shared_ptr<roadfighter::Entity>
        */
        std::shared_ptr<roadfighter::Entity> create_lorry() override;

        /**
        * @fn std::shared_ptr<roadfighter::Entity> create_bullet()
        * @brief Creates a Bullet object
        * @return std::shared_ptr<roadfighter::Entity>
        */
        std::shared_ptr<roadfighter::Entity> create_bullet() override;

    private:
        std::shared_ptr<sf::RenderWindow> window;
    };
}

#endif //ROADFIGHTER_SFMLFACTORY_H
