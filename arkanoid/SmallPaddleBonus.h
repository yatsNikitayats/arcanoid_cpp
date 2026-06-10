#pragma once
#include "Bonus.h"

class SmallPaddleBonus : public Bonus {
public:
    SmallPaddleBonus(float x, float y);
    void apply(Paddle& paddle, Ball& ball, GameState& state) override;
};

