#include "CollisionDetector.h"

CollisionDetector::CollisionDetector():
	ship(nullptr)
{
}

CollisionDetector::~CollisionDetector()
{
}

void CollisionDetector::init(Ship * obj)
{
	ship = obj;
}

void CollisionDetector::run()
{
	CCLOG("Run collision detector");
}

void CollisionDetector::addObject(GameObject * obj)
{
	objects.push_back(obj);
}

void CollisionDetector::removeObject(GameObject * obj)
{
	objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
}

void CollisionDetector::check()
{
	for (auto obj : objects)
	{
		if (obj->getBoundingBox().intersectsRect(ship->getBoundingBox()))
			CCLOG("collision!");
	}
}
