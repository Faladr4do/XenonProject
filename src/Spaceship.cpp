#include "Spaceship.hpp"
#include <iostream>

namespace xenon {
	Spaceship::Spaceship(Vector2D position, Gun gun)
		: Entity(position, Vector2D{ 0.0, 0.0 }),
		health(100.0),
		gun(nullptr),
		texture(0),
		textureWidth(0),
		textureHeight(0),
		animation(64, 64, 4, 0.15f),
		x(368.0f),
		y(268.0f),
		width(64.0f),
		height(64.0f)
	{
	}

	Spaceship::Spaceship(
		GLuint texture,
		int textureWidth,
		int textureHeight
	)
		: Entity(Vector2D{ 368.0, 268.0 }, Vector2D{ 0.0, 0.0 }),
		health(100.0),
		gun(nullptr),
		texture(texture),
		textureWidth(textureWidth),
		textureHeight(textureHeight),
		animation(64, 64, 4, 0.15f),
		x(368.0f),
		y(268.0f),
		width(64.0f),
		height(64.0f)
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

	void Spaceship::Render(Renderer& renderer)
	{
		renderer.Draw(
			texture,
			textureWidth,
			textureHeight,
			x,
			y,
			width,
			height,
			animation.GetCurrentFrame()
		);
	}
}