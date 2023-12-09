#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class Car {

    protected:

    enum Direction {
        Up = 1, Down, Left, Right
    };

    sf::Texture texture;
    sf::Sprite appearance;
    float speed = 5;
    bool isDead = false;
    Direction current_dir;
    int trackID = 0;

    public:
    sf::Sprite* getAppearance();

    void initialize(sf::Vector2f pos);
    void render(sf::RenderWindow& target_w);
    void move();
    virtual void update(sf::Vector2f*){};
    
    void setSpeed(float value);
    void setTrackID(int value);
    int getTrackID();
};