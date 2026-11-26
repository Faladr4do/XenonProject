#include "Spaceship.hpp"
#include <iostream>

namespace xenon {
	Spaceship::Spaceship(Vector2D position, Gun gun)
		: Entity(position, Vector2D{0.0, 0.0}), health(100.0), gun(nullptr)
	{
	}

	void Spaceship::update(double deltaTime) {
		position += velocity * deltaTime;
	}

	void Spaceship::print() const {
		std::cout << "Spaceship at (" << position.x << ", " << position.y << ") with gun type: " << "gun->getType()" << "and " << gun->getAmmo() << " ammo" << std::endl;
	}

	Shot* Spaceship::fire() {
		if (gun) {
			return gun->fire(position);
		}
		return nullptr;
	}

	void Spaceship::takeDamage(double amount) {
		health -= amount;
	}

	double Spaceship::getHealth() const {
		return health;
	}

	Gun* Spaceship::getGun() const {
		return gun;
	}

	void Spaceship::upgradeGun() {
		if (gun) {
			gun->upgrade();
		}
	}

	void Spaceship::reloadGun() {
		if (gun) {
			gun->reload();
		}
	}
}