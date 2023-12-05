#include "arena.h"

Arena::Arena() {

    cornerTexture.loadFromFile("../assets/img/arena/arenaTileCorner.png");

    for (int i = 0; i < 4; i++) {
        arenaTiles[i].setTexture(cornerTexture);
        arenaTiles[i].setScale(0.3, 0.3);
    }

}

void Arena::initialize(sf::RenderWindow& target_w) {
    
    int gap = 50;

    sf::Vector2f padding = {
        target_w.getSize().x - (gap + 2 * arenaTiles[0].getGlobalBounds().width), 
        target_w.getSize().y - (gap + 2 * arenaTiles[0].getGlobalBounds().height)
    };

    for (int i = 0; i < 4; i++) {
        arenaTiles[i].setPosition(
            padding.x / 2 + (i % 2) * (arenaTiles[i].getGlobalBounds().width + gap), 
            padding.y / 2 + (i / 2) * (arenaTiles[i].getGlobalBounds().height + gap)
        );
    }

}

void Arena::render(sf::RenderWindow& target_w) {
    for (int i = 0; i < 4; i++) {
        target_w.draw(arenaTiles[i]);
    }
}