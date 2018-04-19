#include "AsteroidGenerator.h"
#include "cocos2d.h"

USING_NS_CC;

AsteroidGenerator::AsteroidGenerator() :
	spawnInterval(3.0f)
{
}

AsteroidGenerator::~AsteroidGenerator()
{
}

void AsteroidGenerator::init()
{
	Director::getInstance()->getScheduler()->schedule(
		[this](float) {spawnAsteroid();}, this, spawnInterval, false, "customUpdate");
}

void AsteroidGenerator::spawnAsteroid()
{
	CCLOG("spawn");
}
