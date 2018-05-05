#pragma once

#include "cocos2d.h"

class GameObject: public cocos2d::Sprite
{
public:
	virtual void initialize(std::string filename) = 0;
	virtual void move(float dx, float dy) = 0;
	virtual void hit(float damage) = 0;
	virtual void destroy() = 0;
};