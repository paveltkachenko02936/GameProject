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
	names.push_back("Meteors/meteorBrown_big1.png");
	names.push_back("Meteors/meteorBrown_big2.png");
	names.push_back("Meteors/meteorBrown_big3.png");
	names.push_back("Meteors/meteorBrown_big4.png");
	names.push_back("Meteors/meteorBrown_med1.png");
	names.push_back("Meteors/meteorBrown_med2.png");
	names.push_back("Meteors/meteorBrown_small1.png");
	names.push_back("Meteors/meteorBrown_small2.png");
	names.push_back("Meteors/meteorBrown_tiny1.png");
	names.push_back("Meteors/meteorBrown_tiny2.png");

	names.push_back("Meteors/meteorGrey_big1.png");
	names.push_back("Meteors/meteorGrey_big2.png");
	names.push_back("Meteors/meteorGrey_big3.png");
	names.push_back("Meteors/meteorGrey_big4.png");
	names.push_back("Meteors/meteorGrey_med1.png");
	names.push_back("Meteors/meteorGrey_med2.png");
	names.push_back("Meteors/meteorGrey_small1.png");
	names.push_back("Meteors/meteorGrey_small2.png");
	names.push_back("Meteors/meteorGrey_tiny1.png");
	names.push_back("Meteors/meteorGrey_tiny2.png");

	for (size_t i = 0; i < names.size(); i++)
	{
		Sprite* sp = Sprite::create(names[i]);
		sprites.push_back(sp);
	}

	Director::getInstance()->getScheduler()->schedule(
		[this](float) {spawnAsteroid();}, this, spawnInterval, false, "customUpdate");
}

void AsteroidGenerator::spawnAsteroid()
{
	CCLOG("spawn");
}
