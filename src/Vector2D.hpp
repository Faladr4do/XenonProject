#ifndef XENON_VECTOR2D_HPP
#define XENON_VECTOR2D_HPP

namespace xenon {

    struct Vector2D {
        double x{ 0.0 };
        double y{ 0.0 };

        Vector2D& operator+=(Vector2D other);
    };

    Vector2D operator+(Vector2D a, Vector2D b);

    Vector2D operator-(Vector2D a, Vector2D b);

    Vector2D operator*(Vector2D v, double s);
    Vector2D operator*(double s, Vector2D v);

    Vector2D operator/(Vector2D a, double s);
    Vector2D operator/(double s, Vector2D a);

    bool operator==(Vector2D a, Vector2D b);

    bool operator!=(Vector2D a, Vector2D b);

    double length(Vector2D v);
}

#endif