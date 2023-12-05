#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class Arena {
    private:
    sf::Texture cornerTexture;
    sf::Sprite arenaTiles[5];
    sf::Vector2f spriteSize[2];     //1 for center, 1 for corner

    public:
    Arena();

    void initialize(sf::RenderWindow& target_w);

    void render(sf::RenderWindow& target_w);

};