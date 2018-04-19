#include "Ship.h"

USING_NS_CC;



Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::createObject(std::string filename)
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
//	Sprite::setAnchorPoint(Vec2(0,0));
}

void Ship::move(float dx, float dy)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto pos = getPosition();
	auto size = getContentSize();

	// �� ��������� ������� �������� �� �����
	if (pos.x + dx - size.width * _anchorPoint.x < origin.x ||
		pos.x + dx + size.width * _anchorPoint.x > origin.x + visibleSize.width ||
		pos.y + dy - size.height * _anchorPoint.y < origin.y ||
		pos.y + dy + size.height * _anchorPoint.y > origin.y + visibleSize.height)
	{
		captured = false;
		return;
	}

	setPosition(pos.x + dx, pos.y + dy);

}

void Ship::capture(bool value)
{
	captured = value;
}

bool Ship::isCaptured()
{
	return captured;
}














