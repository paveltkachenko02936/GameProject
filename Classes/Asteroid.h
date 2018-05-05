#pragma once

#include "cocos2d.h"
#include "GameObject.h"

class Asteroid: public GameObject
{
public:
	Asteroid();
	~Asteroid();

	void initialize(std::string filename) override;
	void move(float dx, float dy) override;
	void hit(float damage) override;
	void destroy() override;

	void setDamage(float value);
	float getDamage();

	void setSpeed(float value);
	float getSpeed();

	CREATE_FUNC(Asteroid);

private:
	float damage;
	float speed;
};

