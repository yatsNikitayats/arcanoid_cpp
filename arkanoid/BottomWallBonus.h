#pragma once
#include "Bonus.h"

class BottomWallBonus : public Bonus {
public:
    BottomWallBonus(float x, float y);
    void apply(Paddle& paddle, Ball& ball, GameState& state) override;
};

