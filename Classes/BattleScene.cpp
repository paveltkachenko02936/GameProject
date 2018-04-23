#include "BattleScene.h"
#include "Game.h"

USING_NS_CC;

BattleScene::BattleScene():
	ship(nullptr)
{}

Scene * BattleScene::createScene()
{
	return BattleScene::create();
}

bool BattleScene::init()
{
	if (!Scene::init())
		return false;

	auto game = Game::getInstance();
	game->asteroidGenerator->init();

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(BattleScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(BattleScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(BattleScene::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(BattleScene::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	addObjects();

	return true;
}

void BattleScene::onEnter()
{
	Node::onEnter();
	Game::getInstance()->asteroidGenerator->run();
}

void BattleScene::addObjects()
{
	ship = Ship::create();
	ship->initialize("GameObjects/playerShip2_green.png");
	this->addChild(ship);
}


void BattleScene::logProblem(const char * filename)
{
}

void BattleScene::gotoNextScene(Ref * sender)
{
}

bool BattleScene::onTouchBegan(Touch* touch, cocos2d::Event* event)
{
	auto touchPos= touch->getLocation();
	auto box = ship->getBoundingBox();

	if (box.containsPoint(touchPos))
	{
		ship->capture(true);
	}

	return true;
}

void BattleScene::onTouchEnded(Touch* touch, cocos2d::Event* event)
{
	auto touchPos = touch->getLocation();
	auto box = ship->getBoundingBox();

	if (box.containsPoint(touchPos))
	{
		ship->capture(false);
	}
}

void BattleScene::onTouchMoved(Touch* touch, cocos2d::Event* event)
{
	if (ship->isCaptured())
	{
		auto delta = touch->getDelta();
		ship->move(delta.x, delta.y);
	}
}

void BattleScene::onTouchCancelled(Touch* touch, cocos2d::Event* event)
{
	CCLOG("touch cancelled");
}




