#pragma once

#include "cocos2d.h"
#include "Ship.h"

USING_NS_CC;

class BattleScene: public cocos2d::Scene
{
public:

	BattleScene();

	static cocos2d::Scene* createScene();

	virtual bool init();
	void addObjects();

	CREATE_FUNC(BattleScene);

private:
	static void logProblem(const char* filename);
	void gotoNextScene(Ref* sender);

	bool onTouchBegan(Touch* touch, cocos2d::Event* event);
	void onTouchEnded(Touch* touch, cocos2d::Event* event);
	void onTouchMoved(Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(Touch* touch, cocos2d::Event* event);

	Ship* ship;
};

