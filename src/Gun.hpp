#include "Shot.hpp"

enum class GunType { light, medium, heavy };

double powerOf(GunType type);   // light = 1, medium = 2, heavy = 4 (use a switch)

namespace xenon {
	class Gun {
	public:
		Gun(GunType type, double cooldown, int maxAmmo);
		virtual ~Gun() = default;
		GunType getType() const;
		int getAmmo() const;
		void reload();
		void upgrade();
		Shot* fire(Vector2D origin);
		
	private:
		GunType type;
		double cooldown;
		int maxAmmo;
		int ammo;
		void update(double deltaTime);

		bool canFire() const;
		
	};
}