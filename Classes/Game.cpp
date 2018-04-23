#include "Game.h"

Game::Game():
	sceneManager(nullptr),
	asteroidGenerator(nullptr)
{
}

Game* Game::instance = 0;

Game* Game::getInstance()
{
	if (!instance)
		instance = new Game();

	return instance;
}

void Game::init()
{
	sceneManager = new SceneManager();
	asteroidGenerator = new AsteroidGenerator();
	collisionDetector = new CollisionDetector();
}

void Game::run()
{
	sceneManager->switchScene(SceneManager::ESceneType::Start);
}


