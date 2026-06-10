#pragma once
#include <memory>
#include "Block.h"

enum class BlockCategory {
    NORMAL,
    UNBREAKABLE,
    SPEED,
    BONUS
};

class BlockFactory {
public:
    static std::unique_ptr<Block> createBlock(BlockCategory category, float x, float y, int hp = 1);
};

