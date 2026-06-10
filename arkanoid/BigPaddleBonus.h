#pragma once
#include "Bonus.h"

class BigPaddleBonus : public Bonus {
public:
    BigPaddleBonus(float x, float y);
    void apply(Paddle& paddle, Ball& ball, GameState& state) override;
};

