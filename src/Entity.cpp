#include "Entity.hpp"
#include <iostream>

namespace xenon {
    Entity::Entity(Vector2D position, Vector2D velocity)
        : position(position), velocity(velocity)
    {
    }

    void Entity::move(double deltaTime) {
        position += velocity * deltaTime;
    }

    Vector2D Entity::getPosition() const {
        return position;
    }

    Vector2D Entity::getVelocity() const {
        return velocity;
    }
	bool Entity::isActive() const {
		return active;
	}
	void Entity::deactivate() {
		active = false;
	}
    
}