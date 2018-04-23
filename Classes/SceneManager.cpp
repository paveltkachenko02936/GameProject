#include "SceneManager.h"
#include "StartScene.h"
#include "BattleScene.h"

SceneManager::SceneManager():
	currentScene(nullptr)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::switchScene(ESceneType type)
{
	bool firstScene = currentScene == nullptr;
	switch (type)
	{
		case ESceneType::Start:
			currentScene = StartScene::createScene();
			break;

		case ESceneType::Battle:
			currentScene = BattleScene::createScene();
			break;

		default:
			break;
	}

	auto director = Director::getInstance();
	if (firstScene)
		director->runWithScene(currentScene);
	else
		director->replaceScene(currentScene);
}

cocos2d::Scene * SceneManager::getCurrentScene()
{
	return currentScene;
}

