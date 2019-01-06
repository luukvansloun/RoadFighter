//
// Created by luuk on 6-1-19.
//

#include "HighScore.h"

roadfighter::HighScore::HighScore() {
    std::fstream hsfile;
    hsfile.open("HighScore/hs.txt");

    if(!hsfile.is_open()) {
        std::cout << "Couldn't open high score file" << std::endl;
        exit(0);
    }
    else {
        hsfile.seekg(0, hsfile.end);
        if(hsfile.tellg() == 0) {
            for(int i = 0; i < 10; i++) {
                highscores.push_back(0);
            }
        }
        else {
            std::string scores((std::istreambuf_iterator<char>(hsfile)), std::istreambuf_iterator<char>());
            size_t position = 0;
            std::string token;
            while((position = scores.find('-')) != std::string::npos) {
                token = scores.substr(0, position);
                highscores.push_back(std::stoi(token));
                scores.erase(0, position + 1);
            }
        }
    }
    hsfile.close();
}

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

    for(int i = 9; i >= 0; i--) {
        if(i == 9) {
            continue;
        }
        else if(i == 0) {
            if(current_score > highscores[i]) {
                highscores[i] = current_score;
            }
        }
        else {
            if(current_score > highscores[i]) {
                continue;
            }
            else if(current_score < highscores[i]) {
                highscores[i + 1] = current_score;
            }
        }
    }
}

void roadfighter::HighScore::write_to_file() {
    std::fstream hsfile;
    hsfile.open("HighScore/hs.txt");

    if(!hsfile.is_open()) {
        std::cout << "Couldn't open high score file" << std::endl;
        exit(0);
    }
    else {
        hsfile.clear();
        for(int i = 0; i < highscores.size(); i++) {
            if(i == highscores.size() - 1) {
                hsfile << highscores[i];
            }
            else {
                hsfile << highscores[i] << "-";
            }
        }
    }

    hsfile.close();
}
