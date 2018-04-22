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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	float posX = origin.x + visibleSize.width / 2;
	float posY = origin.y + visibleSize.height / 2;
	setPosition(posX, posY);
	setContentSize(image->getContentSize());
}


void Asteroid::move(float dx, float dy)
{
}
