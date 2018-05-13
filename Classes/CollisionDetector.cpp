#include "CollisionDetector.h"
#include "cocos2d.h"

USING_NS_CC;

CollisionDetector::CollisionDetector():
	ship(nullptr)
{
	objectsMap[GameObject::EObjectType::Asteroid] = Objects();
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
		[this](float) {check();}, this, 0.0, false, "collisionDetectorUpdate");
}

void CollisionDetector::addObject(GameObject * obj)
{
	auto it = objectsMap.find(obj->getType());
	if (it != objectsMap.end())
	{
		it->second.push_back(obj);
	}
}

void CollisionDetector::removeObject(GameObject * obj)
{
	auto it = objectsMap.find(obj->getType());
	if (it != objectsMap.end())
	{
		it->second.erase(std::remove(it->second.begin(), it->second.end(), obj), it->second.end());
	}
}

void CollisionDetector::check()
{
	Objects objects;

	// проверяем астероиды
	objects = (objectsMap.find(GameObject::EObjectType::Asteroid))->second;
	for (auto obj : objects)
	{
		if (obj->getBoundingBox().intersectsRect(ship->getBoundingBox()))
		{
			ship->hit(obj->getDamage());
			obj->destroy();
		}
	}
}
