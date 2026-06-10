#include "BonusFactory.h"
#include "BigPaddleBonus.h"
#include "SmallPaddleBonus.h"
#include "FastBallBonus.h"
#include "SlowBallBonus.h"
#include "StickyBonus.h"
#include "BottomWallBonus.h"
#include "RandomTrajectoryBonus.h"

std::unique_ptr<Bonus> BonusFactory::createBonus(BonusType type, float x, float y) {
    switch (type) {
    case BonusType::BIG_PADDLE:      return std::make_unique<BigPaddleBonus>(x, y);
    case BonusType::SMALL_PADDLE:    return std::make_unique<SmallPaddleBonus>(x, y);
    case BonusType::FAST_BALL:       return std::make_unique<FastBallBonus>(x, y);
    case BonusType::SLOW_BALL:       return std::make_unique<SlowBallBonus>(x, y);
    case BonusType::STICKY:          return std::make_unique<StickyBonus>(x, y);
    case BonusType::BOTTOM_WALL:     return std::make_unique<BottomWallBonus>(x, y);
    case BonusType::RANDOM_TRAJECTORY: return std::make_unique<RandomTrajectoryBonus>(x, y);
    default:                         return nullptr;
    }
}

