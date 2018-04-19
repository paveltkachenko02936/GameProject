#pragma once

#include "cocos2d.h"


class StartScene : public cocos2d::Scene
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(StartScene);

private:
	static void logProblem(const char* filename);
	void gotoNextScene(Ref* sender);

};