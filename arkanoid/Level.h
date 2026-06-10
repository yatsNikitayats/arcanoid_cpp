#pragma once
#include <vector>
#include <memory>
#include "Block.h"

class Level {
public:
    Level();
    void generate();
    void draw(sf::RenderWindow& window);

    std::vector<std::unique_ptr<Block>> blocks;
};

