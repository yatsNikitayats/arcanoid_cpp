#include "RandomTrajectoryBonus.h"
#include "Ball.h"
#include "Utils.h"
#include "Config.h"
#include <cmath>

RandomTrajectoryBonus::RandomTrajectoryBonus(float x, float y)
    : Bonus(x, y, sf::Color::White) {
}

void RandomTrajectoryBonus::apply(Paddle& paddle, Ball& ball, GameState& state) {
    float speedVal = std::sqrt(ball.velocity.x * ball.velocity.x + ball.velocity.y * ball.velocity.y);
    float angle = (rnd(Config::RANDOM_ANGLE_MIN, Config::RANDOM_ANGLE_MAX)) * 3.14159265358979f / 180.f;
    ball.velocity.x = std::cos(angle) * speedVal;
    ball.velocity.y = -std::abs(std::sin(angle) * speedVal);
    active = false;
}

