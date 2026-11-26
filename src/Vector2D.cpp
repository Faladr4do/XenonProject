#include "Vector2D.hpp"

#include <cmath>

namespace xenon {
	Vector2D& Vector2D::operator+=(Vector2D other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2D operator+(Vector2D a, Vector2D b) {
		a += b;
		return a;
	}

	Vector2D operator-(Vector2D a, Vector2D b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}
	Vector2D operator*(Vector2D v, double s) {
		v.x *= s;
		v.y *= s;
		return v;
	}
	Vector2D operator*(double s, Vector2D v) {
		return v * s;
	}

	Vector2D operator/(Vector2D a, double s) {
		a.x /= s;
		a.y /= s;
		return a;
	}

	Vector2D operator/(double s, Vector2D a) {
		a.x = s / a.x;
		a.y = s / a.y;
		return a;
	}

	bool operator==(Vector2D a, Vector2D b) {
		return a.x == b.x && a.y == b.y;
	}

	bool operator!=(Vector2D a, Vector2D b) {
		return !(a == b);
	}
	
	double length(Vector2D v) {
		return std::sqrt(v.x * v.x + v.y * v.y);
	}
}