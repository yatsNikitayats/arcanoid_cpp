#include "BonusManager.h"
#include "BonusFactory.h"
#include "Paddle.h"
#include "Ball.h"
#include "Utils.h"
#include <algorithm>

void BonusManager::spawn(float x, float y) {
    int t = rnd(0, 6);
    BonusType type = static_cast<BonusType>(t);
    bonuses.push_back(BonusFactory::createBonus(type, x, y));
}

void BonusManager::update(float dt) {
    for (auto& bonus : bonuses) {
        if (bonus->isActive()) bonus->update(dt);
    }
    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(),
        [](const std::unique_ptr<Bonus>& b) { return !b->isActive(); }),
        bonuses.end());
}

void BonusManager::draw(sf::RenderWindow& window) {
    for (auto& bonus : bonuses) {
        if (bonus->isActive()) bonus->draw(window);
    }
}

void BonusManager::handlePaddleCollision(Paddle& paddle, Ball& ball, GameState& state) {
    for (auto& bonus : bonuses) {
        if (!bonus->isActive()) continue;

        sf::FloatRect bonusRect = bonus->getBounds();
        sf::FloatRect paddleRect = paddle.getBounds();

        bool intersect = (bonusRect.position.x < paddleRect.position.x + paddleRect.size.x &&
            bonusRect.position.x + bonusRect.size.x > paddleRect.position.x &&
            bonusRect.position.y < paddleRect.position.y + paddleRect.size.y &&
            bonusRect.position.y + bonusRect.size.y > paddleRect.position.y);

        if (intersect) {
            bonus->apply(paddle, ball, state);
        }
    }
}

