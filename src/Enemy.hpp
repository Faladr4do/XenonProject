#include "Entity.hpp"

namespace xenon {
	class Enemy : public Entity {
	public:
		Enemy(Vector2D position, Vector2D velocity, double health);
		virtual ~Enemy() = default;
		void update(double deltaTime) override;
		void print() const override;
		void takeDamage(double amount);
		double getHealth() const;
	private:
		double health;
	};
}