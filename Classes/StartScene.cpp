#include "StartScene.h"
#include "Game.h"
#include "SceneManager.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
	return StartScene::create();
}

bool StartScene::init()
{
	if(!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	MenuItemImage* playItem = MenuItemImage::create("play_btn_normal.png", "play_btn_push.png", CC_CALLBACK_1(StartScene::gotoNextScene, this));

	if (playItem == nullptr)
	{
		logProblem("'button1Big.png and button1Small.png'");
		return false;
	}

	float itemX = origin.x + visibleSize.width / 2 - playItem->getContentSize().width / 2;
	float itemY = origin.y + visibleSize.height / 2 - playItem->getContentSize().height / 2;
	playItem->setPosition(itemX, itemY);
	playItem->setAnchorPoint(Vec2(0,0));

	Menu* menu = Menu::create(playItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	Label* label = Label::createWithTTF("Asteroidz", "fonts/kenvector_future.ttf", 35);
	if (label == nullptr)
	{
		logProblem("'fonts/kenvector_future.ttf'");
		return false;
	}

	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label);

	return true;
}

void StartScene::logProblem(const char * filename)
{
	printf("Error while loading: %s\n", filename);
	//printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void StartScene::gotoNextScene(Ref* sender)
{
	Game::getInstance()->sceneManager->switchScene(SceneManager::ESceneType::Battle);
}


