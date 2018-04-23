#pragma once

#include "cocos2d.h"

class AsteroidGenerator
{
public:
	AsteroidGenerator();
	~AsteroidGenerator();

	void init();
	void run();

private:
	void spawnAsteroid();

	std::vector<std::string> names;
	std::vector<cocos2d::Sprite*> sprites;
	float spawnInterval;
	cocos2d::Size sceneSize;
	cocos2d::Vec2 sceneOrigin;
	cocos2d::Scene* scene;
};

