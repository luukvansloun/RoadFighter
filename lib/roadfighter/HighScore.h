//
// Created by luuk on 6-1-19.
//

#ifndef ROADFIGHTER_HIGHSCORE_H
#define ROADFIGHTER_HIGHSCORE_H

#include <iostream>
#include <memory>
#include <vector>
#include "Observer.h"

namespace roadfighter {
    class HighScore : public Observer {
    private:
        int current_score = 0;
        std::vector<int> highscores;

    public:
        HighScore();

        int getCurrent_score() const;

        void setCurrent_score(int current_score);

        const std::vector<int> &getHighscores() const;

        void setHighscores(const std::vector<int> &highscores);

        void update() override;
    };
}


#endif //ROADFIGHTER_HIGHSCORE_H
