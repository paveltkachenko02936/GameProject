#pragma once

#include "cocos2d.h"
#include "Ship.h"

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

	std::vector<GameObject*> objects;
	Ship* ship;
};
