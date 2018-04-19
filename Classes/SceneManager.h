#pragma once

#include "cocos2d.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	enum ESceneType
	{
		Start,
		Battle
	};

	void switchScene(ESceneType type);

private:
	cocos2d::Scene* currentScene;
};

