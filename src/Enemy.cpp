#include "Enemy.hpp"
#include <iostream>

namespace xenon {

    Enemy::Enemy(Vector2D position, Vector2D velocity, double health)
        : Entity(position, velocity), health(health)
    {
    }

    void Enemy::update(double deltaTime) {
		move(deltaTime);
    }

    void Enemy::print() const {
		std::cout << getPosition().x << " " << getPosition().y << " " << health << std::endl;
    }

    void Enemy::takeDamage(double amount) {
        health -= amount;
        if (health <= 0) deactivate();
    }

    double Enemy::getHealth() const {
        return health;
    }
}