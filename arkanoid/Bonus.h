#pragma once
#include <SFML/Graphics.hpp>

class Paddle;
class Ball;

struct GameState {
    bool& stickyEnabled;
    bool& bottomWall;
    bool& ballAttached;
};

class Bonus {
public:
    Bonus(float x, float y, sf::Color color);
    virtual ~Bonus() = default;

    virtual void apply(Paddle& paddle, Ball& ball, GameState& state) = 0;
    void update(float dt);
    void draw(sf::RenderWindow& window);
    bool isActive() const { return active; }
    sf::FloatRect getBounds() const;

protected:
    sf::Vector2f position;
    sf::RectangleShape shape;
    float speed;
    bool active;
};

