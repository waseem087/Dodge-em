#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "car.h"

class Player : public Car {
    public:
        Player();
        void update(sf::Vector2f*) override;
        void updateTrack(sf::Vector2f*) override;
        bool isAlive();
        void setAlive(bool);
        int getLives();
        void setLives(int);

    private:
        bool alive = true;
        int lives = 3;
};