#include "SpeedBlock.h"
#include "Ball.h"
#include "Config.h"
#include <cmath>

SpeedBlock::SpeedBlock(float x, float y, int health)
    : NormalBlock(x, y, health) {
    shape.setFillColor(sf::Color::Yellow);
}

void SpeedBlock::onHit(Ball& ball, BonusManager& bonusManager, int& score) {
    NormalBlock::onHit(ball, bonusManager, score);
    ball.velocity *= Config::SPEED_BLOCK_MULTIPLIER;
    float maxSpeed = Config::MAX_BALL_SPEED;
    if (std::abs(ball.velocity.x) > maxSpeed)
        ball.velocity.x = (ball.velocity.x > 0.f ? 1.f : -1.f) * maxSpeed;
    if (std::abs(ball.velocity.y) > maxSpeed)
        ball.velocity.y = (ball.velocity.y > 0.f ? 1.f : -1.f) * maxSpeed;
}

