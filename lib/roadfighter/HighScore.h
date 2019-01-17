//
// Created by luuk on 6-1-19.
//

#ifndef ROADFIGHTER_HIGHSCORE_H
#define ROADFIGHTER_HIGHSCORE_H

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Observer.h"
#include "Entity.h"

namespace roadfighter {
    class HighScore : public Observer {
    private:
        double current_score = 0;
        bool current_in_hs = false;
        std::vector<double> highscores;

    public:
        HighScore();

        const std::vector<double> &getHighscores() const;

        void update() override;

        void write_to_file();
    };
}


#endif //ROADFIGHTER_HIGHSCORE_H
