#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "car.h"

class Player : public Car {
    public:
    Player();
    void update(sf::Vector2f*) override{};
};