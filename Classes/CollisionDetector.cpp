#include "CollisionDetector.h"
#include "cocos2d.h"

USING_NS_CC;

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
	Director::getInstance()->getScheduler()->schedule(
		[this](float) {check();}, this, 0.06, false, "collisionDetectorUpdate");
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
		{
			ship->hit(0.0);
			obj->destroy();
		}
	}
}
