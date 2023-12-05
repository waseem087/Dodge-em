#include "arena.h"

Arena::Arena() {

    cornerTexture.loadFromFile("../assets/img/arena/arenaTileCorner.png");

    for (int i = 0; i < 4; i++) {
        arenaTiles[i].setTexture(cornerTexture);
        arenaTiles[i].setScale(0.5, 0.5);
    }

}

void Arena::initialize(sf::RenderWindow& target_w) {
    
    int gap = 150;

    sf::Vector2f padding = {
        target_w.getSize().x - (gap + 2 * arenaTiles[0].getGlobalBounds().width), 
        target_w.getSize().y - (gap + 2 * arenaTiles[0].getGlobalBounds().height)
    };

    for (int i = 0; i < 4; i++) {

        arenaTiles[i].setOrigin(
            cornerTexture.getSize().x / 2,
            cornerTexture.getSize().y / 2
        );

        //relative to current scale
        arenaTiles[i].scale(
            (i % 2) ? -1 : 1,
            (i / 2) ? -1 : 1
        );

        this->spriteSize = {
            arenaTiles[i].getGlobalBounds().width,
            arenaTiles[i].getGlobalBounds().height
        };

        arenaTiles[i].setPosition(
            (spriteSize.x + padding.x) / 2 + 
            (i % 2) * (spriteSize.x + gap),

            (spriteSize.y + padding.y) / 2 + 
            (i / 2) * (spriteSize.y + gap)
        );

    }

}

void Arena::render(sf::RenderWindow& target_w) {
    for (int i = 0; i < 4; i++) {
        target_w.draw(arenaTiles[i]);
    }
}