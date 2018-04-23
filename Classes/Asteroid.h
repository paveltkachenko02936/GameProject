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

	CREATE_FUNC(Asteroid);

private:
};

