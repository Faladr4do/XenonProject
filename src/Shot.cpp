#include "Shot.hpp"
#include <iostream>

namespace xenon {
	Shot::Shot(Vector2D position, Vector2D velocity, double power)
		: Entity(position, velocity), power(power)
	{
	}
	void Shot::update(double deltaTime) {
		move(deltaTime);
	}

	void Shot::print() const {
		std::cout << getPosition().x << " " << getPosition().y << " " << power << std::endl;
	}

	double Shot::getPower() const {
		return power;
	}
}