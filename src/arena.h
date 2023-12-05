#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class Arena {
    private:
    // sf::Vector2f tileSize_main = {100, 50};
    // sf::Vector2f tileSize_sub = {50, 50};
    sf::Texture cornerTexture;
    sf::Sprite arenaTiles[5];
    sf::Vector2f spriteSize;
    
    public:
    Arena();

    void initialize(sf::RenderWindow& target_w);

    void render(sf::RenderWindow& target_w);

};