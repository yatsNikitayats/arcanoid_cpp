#include "CollisionManager.h"
#include "Ball.h"
#include "Level.h"
#include "BonusManager.h"
#include "Config.h"
#include <cmath>
#include <algorithm>

enum class HitSide { Left, Right, Top, Bottom };

static HitSide getHitSide(const sf::FloatRect& block, const Ball& ball) {
    float left = block.position.x;
    float right = block.position.x + block.size.x;
    float top = block.position.y;
    float bottom = block.position.y + block.size.y;

    float overlapLeft = (ball.position.x + ball.radius) - left;
    float overlapRight = right - (ball.position.x - ball.radius);
    float overlapTop = (ball.position.y + ball.radius) - top;
    float overlapBottom = bottom - (ball.position.y - ball.radius);

    float minOverlapX = std::min(overlapLeft, overlapRight);
    float minOverlapY = std::min(overlapTop, overlapBottom);

    if (minOverlapX < minOverlapY) {
        return (overlapLeft < overlapRight) ? HitSide::Left : HitSide::Right;
    }
    else {
        return (overlapTop < overlapBottom) ? HitSide::Top : HitSide::Bottom;
    }
}

static void applyHit(Ball& ball, HitSide side, const sf::FloatRect& block) {
    switch (side) {
    case HitSide::Left:
        ball.velocity.x = -std::abs(ball.velocity.x);
        ball.position.x = block.position.x - ball.radius - Config::BALL_BOUNCE_CORRECTION;
        break;
    case HitSide::Right:
        ball.velocity.x = std::abs(ball.velocity.x);
        ball.position.x = block.position.x + block.size.x + ball.radius + Config::BALL_BOUNCE_CORRECTION;
        break;
    case HitSide::Top:
        ball.velocity.y = -std::abs(ball.velocity.y);
        ball.position.y = block.position.y - ball.radius - Config::BALL_BOUNCE_CORRECTION;
        break;
    case HitSide::Bottom:
        ball.velocity.y = std::abs(ball.velocity.y);
        ball.position.y = block.position.y + block.size.y + ball.radius + Config::BALL_BOUNCE_CORRECTION;
        break;
    }
}

int CollisionManager::handleBlockCollisions(Ball& ball, Level& level, BonusManager& bonuses, int& score) {
    for (auto& blockPtr : level.blocks) {
        if (blockPtr->isDestroyed()) continue;

        sf::FloatRect bounds = blockPtr->getBounds();
        bool overlapX = (ball.position.x + ball.radius >= bounds.position.x && ball.position.x - ball.radius <= bounds.position.x + bounds.size.x);
        bool overlapY = (ball.position.y + ball.radius >= bounds.position.y && ball.position.y - ball.radius <= bounds.position.y + bounds.size.y);
        if (!overlapX || !overlapY) continue;

        HitSide side = getHitSide(bounds, ball);
        applyHit(ball, side, bounds);

        blockPtr->onHit(ball, bonuses, score);
        break;
    }
    return 0;
}

