#pragma once
#include <memory>
#include "Bonus.h"

enum class BonusType {
    BIG_PADDLE,
    SMALL_PADDLE,
    FAST_BALL,
    SLOW_BALL,
    STICKY,
    BOTTOM_WALL,
    RANDOM_TRAJECTORY
};

class BonusFactory {
public:
    static std::unique_ptr<Bonus> createBonus(BonusType type, float x, float y);
};

