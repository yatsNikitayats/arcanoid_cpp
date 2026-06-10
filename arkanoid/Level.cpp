#include "Level.h"
#include "BlockFactory.h"
#include "Config.h"

Level::Level() {
    generate();
}

void Level::generate() {
    blocks.clear();
    for (int y = 0; y < Config::BLOCK_ROWS; ++y) {
        for (int x = 0; x < Config::BLOCK_COLS; ++x) {
            float bx = Config::BLOCK_START_X + x * (Config::BLOCK_WIDTH + Config::BLOCK_GAP);
            float by = Config::BLOCK_START_Y + y * (Config::BLOCK_HEIGHT + Config::BLOCK_GAP);
            BlockCategory category = BlockCategory::NORMAL;
            int hp = 1;
            if ((x + y) % 11 == 0) category = BlockCategory::UNBREAKABLE;
            else if ((x + y) % 7 == 0) category = BlockCategory::SPEED;
            else if ((x + y) % 5 == 0) category = BlockCategory::BONUS;
            else if ((x + y) % 3 == 0) hp = 2;
            blocks.push_back(BlockFactory::createBlock(category, bx, by, hp));
        }
    }
}

void Level::draw(sf::RenderWindow& window) {
    for (auto& block : blocks) {
        if (!block->isDestroyed()) block->draw(window);
    }
}

