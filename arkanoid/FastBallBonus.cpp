#include "FastBallBonus.h"
#include "Ball.h"
#include "Config.h"
#include <cmath>

FastBallBonus::FastBallBonus(float x, float y)
    : Bonus(x, y, sf::Color::Yellow) {
}

void FastBallBonus::apply(Paddle& paddle, Ball& ball, GameState& state) {
    ball.velocity *= Config::FAST_BALL_MULTIPLIER;
    float maxSpeed = Config::MAX_BALL_SPEED;
    if (std::abs(ball.velocity.x) > maxSpeed)
        ball.velocity.x = (ball.velocity.x > 0.f ? 1.f : -1.f) * maxSpeed;
    if (std::abs(ball.velocity.y) > maxSpeed)
        ball.velocity.y = (ball.velocity.y > 0.f ? 1.f : -1.f) * maxSpeed;
    active = false;
}

