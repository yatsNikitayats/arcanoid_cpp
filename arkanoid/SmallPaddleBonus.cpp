#include "SmallPaddleBonus.h"
#include "Paddle.h"
#include "Config.h"
#include <algorithm>

SmallPaddleBonus::SmallPaddleBonus(float x, float y)
    : Bonus(x, y, sf::Color::Red) {
}

void SmallPaddleBonus::apply(Paddle& paddle, Ball& ball, GameState& state) {
    paddle.width = std::max(paddle.width - Config::SMALL_PADDLE_DECREMENT, Config::MIN_PADDLE_WIDTH);
    paddle.shape.setSize({ paddle.width, paddle.height });
    paddle.shape.setOrigin({ paddle.width / 2.f, paddle.height / 2.f });
    active = false;
}

