#include "arena.h"

Arena::Arena() {

    cornerTexture.loadFromFile("../assets/img/arena/arenaTileCorner.png");
    centerTexture.loadFromFile("../assets/img/arena/arenaTileCenter.png");

    for (int i = 0; i < 4; i++) {
        arenaTiles[i].setTexture(cornerTexture);
        arenaTiles[i].setScale(cornerScale);
    }

    arenaTiles[4].setTexture(centerTexture);
    arenaTiles[4].setScale(centerScale);

}

void Arena::initialize(sf::RenderWindow& target_w) {
    
    int gap = 150;

    //since all the corner tiles have same dimensions and same scales
    spriteSize[0] = {
        arenaTiles[0].getGlobalBounds().width,
        arenaTiles[0].getGlobalBounds().height
    };

    sf::Vector2f padding = {
        (target_w.getSize().x - (gap + 2 * spriteSize[0].x)) / 2,
        (target_w.getSize().y - (gap + 2 * spriteSize[0].y)) / 2
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

        arenaTiles[i].setPosition(
            (spriteSize[0].x / 2 + padding.x) + 
            (i % 2) * (spriteSize[0].x + gap),

            (spriteSize[0].y / 2 + padding.y)+ 
            (i / 2) * (spriteSize[0].y + gap)
        );

    }

    arenaTiles[4].setOrigin(
        centerTexture.getSize().x / 2,
        centerTexture.getSize().y / 2
    );

    spriteSize[1] = {
        arenaTiles[4].getGlobalBounds().width,
        arenaTiles[4].getGlobalBounds().height
    };

    arenaTiles[4].setPosition(
        target_w.getSize().x / 2,
        target_w.getSize().y / 2
    );

    float wallThickness = cornerScale.x * 56;
    float roadSize =  cornerScale.x * 69;
    float roadMid = (wallThickness * 2 + roadSize) / 2;
    sf::Vector2f trackPointer = {roadMid + padding.x, roadMid + padding.y};

    for (int j = 0; j < 1; j++) {
        ring[j].initialize(trackPointer, target_w);
    }

}

void Arena::render(sf::RenderWindow& target_w) {
    for (int i = 0; i < 5; i++) {
        target_w.draw(arenaTiles[i]);
    }
    ring[0].render(target_w);
}