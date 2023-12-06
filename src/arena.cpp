#include "arena.h"

Arena::Arena() {

    cornerTexture.loadFromFile("../assets/img/arena/arenaTileCorner.png");
    centerTexture.loadFromFile("../assets/img/arena/arenaTileCenter.png");

    for (int i = 0; i < 4; i++) {
        arenaTiles[i].setTexture(cornerTexture);
        arenaTiles[i].setScale(0.5, 0.5);
    }

    arenaTiles[4].setTexture(centerTexture);
    arenaTiles[4].setScale(0.25, 0.25);

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

        this->spriteSize[0] = {
            arenaTiles[i].getGlobalBounds().width,
            arenaTiles[i].getGlobalBounds().height
        };

        arenaTiles[i].setPosition(
            (spriteSize[0].x + padding.x) / 2 + 
            (i % 2) * (spriteSize[0].x + gap),

            (spriteSize[0].y + padding.y) / 2 + 
            (i / 2) * (spriteSize[0].y + gap)
        );

    }

    arenaTiles[4].setOrigin(
        centerTexture.getSize().x / 2,
        centerTexture.getSize().y / 2
    );

    this->spriteSize[1] = {
        arenaTiles[4].getGlobalBounds().width,
        arenaTiles[4].getGlobalBounds().height
    };

    arenaTiles[4].setPosition(
        target_w.getSize().x / 2,
        target_w.getSize().y / 2
    );

}

void Arena::render(sf::RenderWindow& target_w) {
    for (int i = 0; i < 5; i++) {
        target_w.draw(arenaTiles[i]);
    }
}