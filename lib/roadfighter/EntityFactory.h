/**
 * @file EntityFactory.h
 *
 * @brief Header file for EntityFactory class
 *
 * @class roadfighter::EntityFactory
 *
 * @brief This Class contains all the functionalities of the Entity Factory.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_ENTITYFACTORY_H
#define ROADFIGHTER_ENTITYFACTORY_H

#include <iostream>
#include <memory>
#include "Entity.h"

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class EntityFactory {
    public:
        /**
         * @fn virtual std::shared_ptr<roadfighter::Entity> create_playercar()
         * @brief Declaration of the create_playercar (Used by the derived SFML Factory Class)
         */
        virtual std::shared_ptr<roadfighter::Entity> create_playercar() = 0;

        /**
         * @fn virtual std::shared_ptr<roadfighter::Entity> create_racingcar()
         * @brief Declaration of the create_racingcar (Used by the derived SFML Factory Class)
         */
        virtual std::shared_ptr<roadfighter::Entity> create_racingcar() = 0;

        /**
         * @fn virtual std::shared_ptr<roadfighter::Entity> create_truck()
         * @brief Declaration of the create_truck (Used by the derived SFML Factory Class)
         */
        virtual std::shared_ptr<roadfighter::Entity> create_truck() = 0;

        /**
         * @fn virtual std::shared_ptr<roadfighter::Entity> create_lorry()
         * @brief Declaration of the create_lorry (Used by the derived SFML Factory Class)
         */
        virtual std::shared_ptr<roadfighter::Entity> create_lorry() = 0;

        /**
         * @fn virtual std::shared_ptr<roadfighter::Entity> create_bullet()
         * @brief Declaration of the create_bullet (Used by the derived SFML Factory Class)
         */
        virtual std::shared_ptr<roadfighter::Entity> create_bullet() = 0;
    };
}


#endif //ROADFIGHTER_ENTITYFACTORY_H
