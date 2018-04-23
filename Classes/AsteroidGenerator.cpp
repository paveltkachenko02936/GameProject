#include "Game.h"
#include "AsteroidGenerator.h"
#include "Asteroid.h"
#include "cocos2d.h"
#include <stdlib.h>
#include <time.h>

USING_NS_CC;

AsteroidGenerator::AsteroidGenerator() :
	spawnInterval(3.0f),
	numAsteroids(0),
	speedMul(1)
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
}

void AsteroidGenerator::run()
{
	auto director = Director::getInstance();
	sceneSize = director->getVisibleSize();
	sceneOrigin = director->getVisibleOrigin();

	srand(time(NULL));
	Director::getInstance()->getScheduler()->schedule(
		[this](float) {spawnAsteroid();}, this, settings.spawnInterval, false, "customUpdate");
}

void AsteroidGenerator::spawnAsteroid()
{
	if (numAsteroids > 0 && numAsteroids % settings.objectsPerStage == 0)
	{
		speedMul *= settings.speedMultiplier;
		CCLOG("speedIncreased!!");
	}

	int index = rand() % names.size();
	Asteroid* asteroid = Asteroid::create();
	asteroid->initialize(names[index]);
	asteroid->setRotation(rand() % 360);
	float speed = (settings.startSpeed + rand() % 40) * speedMul; //задавыть из файла настроек при инициализации, модификаторы применять тут
	asteroid->setSpeed(speed); 
	auto size = asteroid->getContentSize();
	int minX = int(sceneOrigin.x + size.width * asteroid->getAnchorPoint().x);
	int maxX = int(sceneOrigin.x + sceneSize.width - size.width * asteroid->getAnchorPoint().x);
	int posX = minX + rand() % (maxX - minX);
	int posY = int(sceneOrigin.y + sceneSize.height + size.height * asteroid->getAnchorPoint().y);

	asteroid->setPosition(posX, posY);
	Game::getInstance()->sceneManager->getCurrentScene()->addChild(asteroid);
	numAsteroids++;
	asteroid->move(0, -sceneSize.height - size.height);
}
