#include "BigPaddleBonus.h"
#include "Paddle.h"
#include "Config.h"
#include <algorithm>

BigPaddleBonus::BigPaddleBonus(float x, float y)
    : Bonus(x, y, sf::Color::Green) {
}

void BigPaddleBonus::apply(Paddle& paddle, Ball& ball, GameState& state) {
    paddle.width = std::min(paddle.width + Config::BIG_PADDLE_INCREMENT, Config::MAX_PADDLE_WIDTH);
    paddle.shape.setSize({ paddle.width, paddle.height });
    paddle.shape.setOrigin({ paddle.width / 2.f, paddle.height / 2.f });
    active = false;
}

