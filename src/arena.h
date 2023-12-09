#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

#include "track.h"
#include "food.h"

class Arena {
    private:
    sf::Texture cornerTexture, centerTexture;
    sf::Sprite arenaTiles[5];
    sf::Vector2f spriteSize[2];     //1 for center, 1 for corner

    sf::Vector2f cornerScale = {0.5, 0.5};
    sf::Vector2f centerScale = {0.25, 0.25};

    Track ring[4];

    FoodItem* foodMap[8][8];
    
    public:
    Arena();
    ~Arena();

    void initialize(sf::RenderWindow& target_w);

    void render(sf::RenderWindow& target_w);

    void foodConsumption(Player& player);

    Track* getTrack(int index);

};