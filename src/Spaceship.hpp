#pragma once

#include "Entity.hpp"
#include "Gun.hpp"

namespace xenon {
	class Spaceship : public Entity {
	public:
		Spaceship(Vector2D position,Gun gun);
		virtual ~Spaceship() = default;
		void update(double deltaTime) override;
		void print() const override;
		void takeDamage(double amount);
		double getHealth() const;
		Gun* getGun() const;

		void upgradeGun();
		void reloadGun();
		//const Gun& getGun() const;

		Shot* fire();

	private:
		
		double health;
		Gun* gun;
	};
}