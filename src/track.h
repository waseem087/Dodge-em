#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Track {
    public:
        void initialize(sf::Vector2f referenceCorner, sf::RenderWindow& target_w);
        void render(sf::RenderWindow& target_w);

        sf::Vector2f* getCorners();

    private:
        sf::VertexArray corner;
        sf::Vector2f corners[4];
};