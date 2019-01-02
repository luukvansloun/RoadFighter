//
// Created by luuk on 19-12-18.
//

#ifndef ROADFIGHTER_BULLETSFML_H
#define ROADFIGHTER_BULLETSFML_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <Bullet.h>
#include <Transformation.h>
#include <Random.h>


namespace roadfighterSFML {
    class BulletSFML : public roadfighter::Bullet {
    private:
        float width;
        float height;
        sf::Texture texture;
        sf::RectangleShape sprite;
        std::shared_ptr<sf::RenderWindow> window;

    public:
        BulletSFML(std::shared_ptr<sf::RenderWindow> window);

        void change_position();

        void draw();

        float getWidth() const;

        float getHeight() const;
    };
}


#endif //ROADFIGHTER_BULLETSFML_H
