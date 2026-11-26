#include "Gun.hpp"
#include <stdexcept>

double powerOf(GunType type) {
	switch (type) {
	case GunType::light:
		return 1.0;
	case GunType::medium:
		return 2.0;
	case GunType::heavy:
		return 4.0;
	}
	throw std::invalid_argument("Unknown gun type.");
}

namespace xenon {
	Gun::Gun(GunType type, double cooldown, int maxAmmo)
		: type(type), cooldown(cooldown), maxAmmo(maxAmmo), ammo(maxAmmo)
	{
		if (maxAmmo <= 0 || cooldown < 0) {
			throw std::invalid_argument("maxAmmo must be non-negative and cooldown must be non-negative.");
		}
	}
	GunType Gun::getType() const {
		return type;
	}
	int Gun::getAmmo() const {
		return ammo;
	}

	void Gun::update(double deltaTime) {
		cooldown -= deltaTime;
	}

	Shot* Gun::fire(Vector2D origin) {
		if (canFire()) {
			--ammo;
			return new Shot(origin, Vector2D{ 0, -1 }, powerOf(type));
		}
		return nullptr;
	}

	bool Gun::canFire() const {
		return ammo > 0 && cooldown <= 0;
	}

	void Gun::reload() {
		ammo = maxAmmo;
	}
	void Gun::upgrade() {
		switch (type) {
		case GunType::light:
			type = GunType::medium;
			break;
		case GunType::medium:
			type = GunType::heavy;
			break;
		case GunType::heavy:
			// Already at max level, do nothing
			break;
		}
	}
}