#pragma once

#include "cocos2d.h"

class AsteroidGenerator
{
public:
	AsteroidGenerator();
	~AsteroidGenerator();

	void init();

private:
	void spawnAsteroid();

	float spawnInterval;
	std::vector<std::string> names;
	std::vector<cocos2d::Sprite*> sprites;
};

