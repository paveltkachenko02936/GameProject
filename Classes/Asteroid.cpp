#include "Asteroid.h"
#include "Game.h"

USING_NS_CC;

Asteroid::Asteroid()
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::initialize(std::string filename)
{
	Sprite* image = Sprite::create(filename);
	addChild(image);
	image->setAnchorPoint(Vec2(0, 0));
	setContentSize(image->getContentSize());
}


void Asteroid::move(float dx, float dy)
{
	Game::getInstance()->collisionDetector->addObject(this);

	auto action = MoveBy::create(std::abs(dy) / speed, Point(dx, dy));
	auto callback = CallFunc::create(this, CC_CALLFUNC_SELECTOR(Asteroid::destroy));
	auto sequence = Sequence::create(action, callback, NULL);

	this->runAction(sequence);
}

void Asteroid::hit(float damage)
{
}

void Asteroid::setDamage(float value)
{
	damage = value;
}

float Asteroid::getDamage()
{
	return damage;
}

void Asteroid::setSpeed(float value)
{
	speed = value;
}

float Asteroid::getSpeed()
{
	return speed;
}

void Asteroid::destroy()
{
	this->stopAllActions();
	Game::getInstance()->collisionDetector->removeObject(this);
	this->removeFromParentAndCleanup(true);
}
