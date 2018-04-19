#pragma once

#include "cocos2d.h"
#include "GameObject.h"

class Ship: public cocos2d::Sprite, GameObject
{
public:
	Ship();
	~Ship();

	void createObject(std::string filename);
	void move(float dx, float dy) override;
	void capture(bool value) override;

	bool isCaptured();

	CREATE_FUNC(Ship);

	
private:
	bool captured;
};



