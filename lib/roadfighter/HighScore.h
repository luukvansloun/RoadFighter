/**
 * @file HighScore.h
 *
 * @brief Header file for HighScore class
 *
 * @class roadfighter::HighScore
 *
 * @brief This Class contains all the functionalities of the HighScore System.
 *
 * @authors Luuk van Sloun
 */

#ifndef ROADFIGHTER_HIGHSCORE_H
#define ROADFIGHTER_HIGHSCORE_H

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include "Observer.h"
#include "Entity.h"

/**
* @namespace roadfighter
* @brief This Namespace contains all elements of the roadfighter library
*/
namespace roadfighter {
    class HighScore : public Observer {
    private:
        double current_score = 0;
        bool current_in_hs = false;
        std::vector<double> highscores;

    public:
        /**
        * @fn HighScore()
        * @brief Constructor for the HighScore Class
        * @post New HighScore object has been created
        */
        HighScore();

        /**
        * @fn const std::vector<double> &getHighscores() const
        * @brief Returns the vector of High Scores
        * @return const std::vector<double>
        */
        const std::vector<double> &getHighscores() const;

        /**
        * @fn void update() override
        * @brief Updates the score using the Observer Pattern
        */
        void update() override;

        /**
        * @fn void write_to_file()
        * @brief Writes the new high scores to the hs.txt file
        */
        void write_to_file();
    };
}


#endif //ROADFIGHTER_HIGHSCORE_H
