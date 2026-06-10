#include "SlowBallBonus.h"
#include "Ball.h"
#include "Config.h"
SlowBallBonus::SlowBallBonus(float x, float y)
    : Bonus(x, y, sf::Color::Blue) {
}

void SlowBallBonus::apply(Paddle& paddle, Ball& ball, GameState& state) {
    ball.velocity *= Config::SLOW_BALL_MULTIPLIER;
    active = false;
}

