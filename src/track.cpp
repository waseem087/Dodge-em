#include "track.h"

void Track::initialize(sf::Vector2f referenceCorner, sf::RenderWindow& target_w) {

    this->corner.setPrimitiveType(sf::LineStrip);
    this->corner.resize(5);

    for (int i = 0; i < 5; i++) {

        sf::Vector2f positionVector = {
            (i == 1 || i == 2) ? target_w.getSize().x - referenceCorner.x : referenceCorner.x,
            (i / 2 == 1) ? target_w.getSize().y - referenceCorner.y : referenceCorner.y
        };

        this->corner[i].position = positionVector;
        this->corner[i].color = sf::Color::White;

        if (i < 4)
            this->corners[i] = positionVector;

    }

}

void Track::render(sf::RenderWindow& target_w) {

    target_w.draw(corner);

}

sf::Vector2f* Track::getCorners() {
    return corners;
}