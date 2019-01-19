/**
 * @file World.h
 *
 * @brief Header file for World class
 *
 * @class roadfighter::World
 *
 * @brief This Class contains all the functionalities of the World.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cmath>
#include "PlayerCar.h"
#include "Random.h"

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class World : public roadfighter::Entity {
    private:
        std::shared_ptr<roadfighter::Entity> playercar;
        std::vector<std::shared_ptr<roadfighter::Entity>> entities;
        std::vector<std::shared_ptr<roadfighter::Entity>> opponents;
        float left_border = -2.45;
        float right_border = 0.025;

    public:
        /**
        * @fn World()
        * @brief Constructor for the World Class
        * @post New World object has been created
        */
        World()=default;

        /**
        * @fn const std::shared_ptr<roadfighter::Entity> &getPlayercar() const
        * @brief Returns the Player car object
        * @return std::shared_ptr<roadfighter::Entity>
        */
        const std::shared_ptr<roadfighter::Entity> &getPlayercar() const;

        /**
        * @fn void setPlayercar(const std::shared_ptr<roadfighter::Entity> &playercar)
        * @param const std::shared_ptr<roadfighter::Entity> &playercar
        * @brief Sets the Player car object
        */
        void setPlayercar(const std::shared_ptr<roadfighter::Entity> &playercar);

        /**
        * @fn void move_player_right()
        * @brief Moves the Player car to the right
        */
        void move_player_right();

        /**
        * @fn void move_player_left()
        * @brief Moves the Player car to the left
        */
        void move_player_left();

        /**
        * @fn bool move_player_up()
        * @brief Moves the Player car upwards. Returns True if out of screen (End of Game)
        * @return bool
        */
        bool move_player_up();

        /**
        * @fn void incr_speed()
        * @brief Increases the Player car's speed
        */
        void incr_speed();

        /**
        * @fn void decr_speed()
        * @brief Decreases the Player car's speed
        */
        void decr_speed();

        /**
        * @fn const std::vector<std::shared_ptr<Entity>> &getEntities() const
        * @brief Returns the World entities
        * @return std::vector<std::shared_ptr<Entity>>
        */
        const std::vector<std::shared_ptr<Entity>> &getEntities() const;

        /**
        * @fn void add_entity(std::shared_ptr<roadfighter::Entity> entity)
        * @param std::shared_ptr<roadfighter::Entity> entity
        * @brief Adds an entity to the vector of World entities
        */
        void add_entity(std::shared_ptr<roadfighter::Entity> entity);

        /**
        * @fn void add_opponent(std::shared_ptr<roadfighter::Entity> opponent)
        * @param std::shared_ptr<roadfighter::Entity> opponent
        * @brief Adds an opponent to the vector of World opponent cars
        */
        void add_opponent(std::shared_ptr<roadfighter::Entity> opponent);

        /**
        * @fn void update_all()
        * @brief Updates all entities in the world (Player car, Opponents and other Entities)
        */
        void update_all();

        /**
        * @fn void start_update()
        * @brief Specific update function for the start of the game
        */
        void start_update();

        /**
        * @fn const std::vector<std::shared_ptr<Entity>> &getOpponents() const
        * @brief Returns the World opponent cars
        * @return std::vector<std::shared_ptr<Entity>>
        */
        const std::vector<std::shared_ptr<Entity>> &getOpponents() const;

        /**
        * @fn void draw() override
        * @brief Calls the draw function of all entities
        */
        void draw() override;

        /**
        * @fn bool detect_collision(std::shared_ptr<roadfighter::Entity> entity_one,
                              std::shared_ptr<roadfighter::Entity> entity_two)
        * @param std::shared_ptr<roadfighter::Entity> entity_one
        * @param std::shared_ptr<roadfighter::Entity> entity_two
        * @brief Returns True if collision is detected between two entities
        * @return bool
        */
        bool detect_collision(std::shared_ptr<roadfighter::Entity> entity_one,
                              std::shared_ptr<roadfighter::Entity> entity_two);

        /**
        * @fn void crashing(std::shared_ptr<roadfighter::Entity> entity)
        * @param std::shared_ptr<roadfighter::Entity> entity
        * @brief Updates the entities position or status according to it's crash type
        */
        void crashing(std::shared_ptr<roadfighter::Entity> entity);
    };
}


#endif //ROADFIGHTER_WORLD_H
