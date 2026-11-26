#include "World.hpp"
#include <stdexcept>

namespace xenon {
	World::World(double width, double height) : width(width), height(height) {
		if (width <= 0 || height <= 0) {
			throw std::invalid_argument("Width and height must be positive.");
		}
	}

	World::~World() {
		for (Entity* entity : entities) {
			delete entity;
		}
	}

	void World::update(double deltaTime) {
		for (Entity* entity : entities) {
			if (entity->isActive()) {
				entity->update(deltaTime);
			}
			if (entity->getPosition().x <= width) entity->deactivate();
			if (entity->getPosition().y <= height) entity->deactivate();
		}
		
		for (auto it = entities.begin(); it != entities.end(); ) {
			if (!(*it)->isActive()) {
				delete* it;                // free the entity first...
				it = entities.erase(it);   // ...then drop the pointer from the vector
			}
			else {
				++it;
			}
		}
	}
	void World::add(Entity* entity) {
		if (entity != nullptr) {
			entities.push_back(entity);
		}
	}

	Spaceship* World::findShip() {
		for (Entity* entity : entities) {
			if (Spaceship* ship = dynamic_cast<Spaceship*>(entity)) {
				return ship;
			}
		}
		return nullptr;
	}
}