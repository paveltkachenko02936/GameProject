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

	int numAsteroids;
	float speedMul;
	std::vector<std::string> names;
	std::vector<cocos2d::Sprite*> sprites;
	float spawnInterval;
	cocos2d::Size sceneSize;
	cocos2d::Vec2 sceneOrigin;
	cocos2d::Scene* scene;

	// גûםוסעט ג מעהוכüםûי פאיכ
	struct Settings
	{
		float startSpeed = 70.0f;
		float speedMultiplier = 1.2f;
		int objectsPerStage = 30;
		float spawnInterval = 2;
		float spawnMul = 0.8;
	};

	Settings settings;

};

