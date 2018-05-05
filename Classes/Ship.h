#pragma once

#include "cocos2d.h"
#include "GameObject.h"

class Ship: public GameObject
{
public:
	Ship();
	~Ship();

	void initialize(std::string filename) override;
	void move(float dx, float dy) override;
	void hit(float damage) override;
	void destroy() override;

	void capture(bool value);

	bool isCaptured();

	CREATE_FUNC(Ship);

	
private:
	bool captured;
};



