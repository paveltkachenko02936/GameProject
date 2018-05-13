#pragma once

#include "cocos2d.h"
#include "Ship.h"
#include "Asteroid.h"

class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();

	void init(Ship* obj);
	void run();
	void addObject(GameObject* obj);
	void removeObject(GameObject* obj);

private:
	void check();

	typedef std::vector<GameObject*> Objects;
	std::map<GameObject::EObjectType, Objects> objectsMap;
	Ship* ship;
};
