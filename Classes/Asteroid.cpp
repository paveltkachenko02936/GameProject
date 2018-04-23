#include "Asteroid.h"

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
	auto sequence = Sequence::create(
		MoveBy::create(std::abs(dy) / speed, Point(dx, dy)),
		RemoveSelf::create(true),
		nullptr);

	this->runAction(sequence);
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
