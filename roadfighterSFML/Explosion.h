//
// Created by luuk on 18-12-18.
//

#ifndef ROADFIGHTER_EXPLOSION_H
#define ROADFIGHTER_EXPLOSION_H

#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

namespace roadfighterSFML {
    class Explosion {
    private:
        std::chrono::milliseconds total_time;
        std::chrono::milliseconds switch_time;
        std::chrono::milliseconds current_time;
        int current_image;

    public:
        Explosion();

        virtual ~Explosion();

        sf::IntRect texture_rect;

        bool finished = false;

        void Update();
    };
}



#endif //ROADFIGHTER_EXPLOSION_H
