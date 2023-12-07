#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

struct Track {

    sf::VertexArray corner;
    
    void initialize(sf::Vector2f referenceCorner, sf::RenderWindow& target_w);
    
    void render(sf::RenderWindow& target_w);

};