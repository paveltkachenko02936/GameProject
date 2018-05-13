#pragma once

#include "cocos2d.h"

class GameObject: public cocos2d::Sprite
{
public:
	enum EObjectType
	{
		Ship,
		Asteroid
	};

	virtual void initialize(std::string filename) = 0;
	virtual void move(float dx, float dy) = 0;
	virtual void hit(float damage) = 0;
	virtual void destroy() = 0;

	void setDamage(float value) { damage = value; };
	float getDamage() { return damage; };

	void setSpeed(float value) { speed = value; }
	float getSpeed() { return speed; }

	EObjectType getType() { return type; }

protected:
	EObjectType type;
	float damage = 0;
	float speed = 0;
};