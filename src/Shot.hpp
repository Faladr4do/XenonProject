#include "Entity.hpp"

namespace xenon {
	class Shot : public Entity {
	public:
		Shot(Vector2D position, Vector2D velocity, double power);
		virtual ~Shot() = default;
		void update(double deltaTime) override;
		void print() const override;
		double getPower() const;
	private:
		double power;
	};
}