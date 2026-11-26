// Entity.hpp
#ifndef XENON_ENTITY_HPP
#define XENON_ENTITY_HPP

#include "Vector2D.hpp"

namespace xenon {

    class Entity {
    public:
        Entity(Vector2D position, Vector2D velocity);
        virtual ~Entity() = default;

        virtual void update(double deltaTime) = 0;   // pure virtual
        virtual void print() const = 0;              // pure virtual

        Vector2D getPosition() const;
        Vector2D getVelocity() const;
        void setVelocity(Vector2D velocity);

        bool isActive() const;
        void deactivate();

        void move(double deltaTime);   // position += velocity * deltaTime

    protected:
        Vector2D position;
        Vector2D velocity;
        bool active{ true };
    };

}

#endif