//
// Created by luuk on 18-12-18.
//

#include "Explosion.h"

roadfighterSFML::Explosion::Explosion() {
    total_time = std::chrono::milliseconds(800);
    switch_time = std::chrono::milliseconds(100);
    current_time = std::chrono::milliseconds(0);
    current_image = 0;

    texture_rect.width = 56;
    texture_rect.height = 81;
}

roadfighterSFML::Explosion::~Explosion() {}

void roadfighterSFML::Explosion::Update() {
    current_time += std::chrono::milliseconds(16);
    if(switch_time <= current_time) {
        current_time = std::chrono::milliseconds(0);
        total_time -= switch_time;
        current_image++;

        if(current_image >= 7) {
            current_image = 0;
            this->finished = true;
        }
    }

    texture_rect.left = current_image * 56;
}


