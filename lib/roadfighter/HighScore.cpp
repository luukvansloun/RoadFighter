//
// Created by luuk on 6-1-19.
//

#include "HighScore.h"

roadfighter::HighScore::HighScore() {}

int roadfighter::HighScore::getCurrent_score() const {
    return current_score;
}

void roadfighter::HighScore::setCurrent_score(int current_score) {
    HighScore::current_score = current_score;
}

const std::vector<int> &roadfighter::HighScore::getHighscores() const {
    return highscores;
}

void roadfighter::HighScore::setHighscores(const std::vector<int> &highscores) {
    HighScore::highscores = highscores;
}

void roadfighter::HighScore::update() {
    this->current_score = getSubject()->getScore();
}
