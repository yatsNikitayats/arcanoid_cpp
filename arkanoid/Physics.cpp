#include "Physics.h"
#include "Ball.h"
#include "Paddle.h"
#include "Config.h"
#include <cmath>

void Physics::handleWallCollision(Ball& ball) {
    if (ball.position.x - ball.radius <= 0.f) {
        ball.position.x = ball.radius;
        ball.velocity.x *= -1.f;
    }
    if (ball.position.x + ball.radius >= Config::WINDOW_WIDTH) {
        ball.position.x = Config::WINDOW_WIDTH - ball.radius;
        ball.velocity.x *= -1.f;
    }
    if (ball.position.y - ball.radius <= 0.f) {
        ball.position.y = ball.radius;
        ball.velocity.y *= -1.f;
    }
}

void Physics::handlePaddleCollision(Ball& ball, const Paddle& paddle, bool& stickyEnabled, bool& ballAttached) {
    sf::FloatRect bounds = paddle.getBounds();
    bool overlapX = (ball.position.x + ball.radius >= bounds.position.x && ball.position.x - ball.radius <= bounds.position.x + bounds.size.x);
    bool overlapY = (ball.position.y + ball.radius >= bounds.position.y && ball.position.y - ball.radius <= bounds.position.y + bounds.size.y);

    if (overlapX && overlapY && ball.velocity.y > 0.f) {
        ball.position.y = bounds.position.y - ball.radius;
        float hitPos = (ball.position.x - paddle.position.x) / (paddle.width / 2.f);
        ball.velocity.x = hitPos * Config::PADDLE_HIT_FORCE;
        if (stickyEnabled) {
            ballAttached = true;
            stickyEnabled = false;
            return;
        }
        ball.velocity.y *= -1.f;
    }
}

