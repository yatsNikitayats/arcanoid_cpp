#include "BlockFactory.h"
#include "NormalBlock.h"
#include "UnbreakableBlock.h"
#include "SpeedBlock.h"
#include "BonusBlock.h"

std::unique_ptr<Block> BlockFactory::createBlock(BlockCategory category, float x, float y, int hp) {
    switch (category) {
    case BlockCategory::NORMAL:      return std::make_unique<NormalBlock>(x, y, hp);
    case BlockCategory::UNBREAKABLE: return std::make_unique<UnbreakableBlock>(x, y);
    case BlockCategory::SPEED:       return std::make_unique<SpeedBlock>(x, y, hp);
    case BlockCategory::BONUS:       return std::make_unique<BonusBlock>(x, y, hp);
    default:                         return nullptr;
    }
}

