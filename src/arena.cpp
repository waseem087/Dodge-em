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

    populateFoodMap();

}

void Arena::populateFoodMap() {
    srand(time(0));

    for (int j = 0; j < 8; j++) {
        for (int z = 0; z < 8; z++) {

            int magicNum = rand() % 4;
            
            switch (magicNum) {
            case 0:
                foodMap[j][z] = new Rect(sf::Vector2f(40, 20));
                break;
            case 1:
                foodMap[j][z] = new Cir(10);
                break;
            case 2:
                foodMap[j][z] = new Hex(10);
                break;
            case 3:
                foodMap[j][z] = new Tri(10);
                break;
            default:
                break;
            }
        }
    }
}

void Arena::foodDistribution() {

    int gap = 150;

    for (int i = 0; i < 4; i++) {

        int foodCount = 28 - (8 * i);

        sf::Vector2f* corner = ring[i].getCorners();

        sf::Vector2f spacing = {
            (corner[1].x - corner[0].x - gap) / (foodCount / 4),
            (corner[2].y - corner[1].y - gap) / (foodCount / 4)
        };

        int foodPerSide = (foodCount / 4) + 1;

        sf::Vector2i foodIndex = {0, 0};

        //food distribution
        for (int j = i; j < foodPerSide + i; j++) {
            
            int z = i;

            while (z < foodPerSide + i) {
                foodMap[j][z]->setPosition(sf::Vector2f(
                    corner[0].x + spacing.x * foodIndex.x + ((z > 3) ? gap : 0),
                    corner[0].y + spacing.y * foodIndex.y + ((j > 3) ? gap : 0)
                ));

                foodMap[j][z]->update(foodMap[j][z]->getAppearance());

                if ((j == i || j == foodPerSide - 1 + i)){
                    foodIndex.x++;
                    z++;
                }
                else {
                    foodIndex.x += foodPerSide - 1;
                    z += foodPerSide - 1;
                }
            }

            foodIndex.x = 0;
            foodIndex.y++;

        }
    
    }

}

Arena::~Arena() {
    for (int j = 0; j < 8; j++) {
        for (int z = 0; z < 8; z++) {
            delete foodMap[j][z];
        }
    }
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

    for (int j = 0; j < 4; j++) {
        ring[j].initialize(trackPointer, target_w);
        trackPointer += sf::Vector2f(wallThickness + roadSize, wallThickness + roadSize);
    }

    foodDistribution();

}

void Arena::render(sf::RenderWindow& target_w) {
    for (int i = 0; i < 5; i++) {
        target_w.draw(arenaTiles[i]);
    }

    for (int j = 0; j < 8; j++) {
        for (int z = 0; z < 8; z++) {
            if (foodMap[j][z] != nullptr)
                foodMap[j][z]->render(target_w, foodMap[j][z]->getAppearance());
        }
    }

}

void Arena::foodConsumption(Player& player, int& scores, Opponent& Opponent, sf::Clock& ticks) {
    for (int i = 0; i < 8; i++) {
        for (int z = 0; z < 8; z++) {
            if (foodMap[i][z] == nullptr || !foodMap[i][z]->collides(player, foodMap[i][z]->getAppearance())) continue;
            
            ticks.restart();
            foodMap[i][z]->givePerk(player, scores, Opponent);
            delete foodMap[i][z];
            foodMap[i][z] = nullptr;
            foodLeft--;
        }
    }
}

int Arena::getFoodLeft() {
    return foodLeft;
}

void Arena::setFoodLeft(int value) {
    foodLeft = value;
}

Track* Arena::getTrack(int index) {
    return &ring[index];
}

sf::Sprite* Arena::getArenaTile(int index) {
    return &arenaTiles[index];
}