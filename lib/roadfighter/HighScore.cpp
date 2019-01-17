//
// Created by luuk on 6-1-19.
//

#include "HighScore.h"

roadfighter::HighScore::HighScore() {
    std::ifstream hsfile("HighScore/hs.txt");

    if(!hsfile.is_open()) {
        std::cout << "Couldn't open high score file" << std::endl;
        exit(0);
    }
    else {
        std::string score;
        while (getline(hsfile, score)) {
            highscores.push_back(std::stod(score));
        }
    }
    hsfile.close();
}

const std::vector<double> &roadfighter::HighScore::getHighscores() const {
    return highscores;
}

void roadfighter::HighScore::update() {
    current_score = getSubject()->getScore();

    if(!current_in_hs) {
        if(current_score > highscores[0]) {
            current_in_hs = true;
        }
    }
    else {
        highscores[0] = current_score;
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
        std::sort(highscores.begin(), highscores.end());
        for(int i = 0; i < highscores.size(); i++) {
            if(i == highscores.size() - 1) {
                hsfile << highscores[i];
            }
            else {
                hsfile << highscores[i] << "\n";
            }
        }
    }

    hsfile.close();
}
