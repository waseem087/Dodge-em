#include <SFML/Graphics.hpp>
#include <iostream>

#include "track.h"

#pragma once

class Car {

    public:
    enum Direction {
        Up = 1, Down, Left, Right
    };
    sf::Sprite* getAppearance();

    void initialize(sf::Vector2f pos);
    void render(sf::RenderWindow& target_w);
    void move();
    virtual void update(sf::Vector2f*){};
    virtual void updateTrack(sf::Vector2f*){};
    
    void setDirection(Direction dir);
    Direction getDirection();
    void setSpeed(float value);
    void setTrackID(int value);
    int getTrackID();

    protected:
    sf::Texture texture;
    sf::Sprite appearance;
    float speed = 5;
    Direction current_dir;
    int trackID = 0;
};