#pragma once

#include "AsteroidGenerator.h"
#include "SceneManager.h"

class Game
{
public:
	//-------------------
	static Game* getInstance();
	//-------------------
	void init();
	void run();

	AsteroidGenerator* asteroidGenerator;
	SceneManager* sceneManager;
	
private:
	//-------------------
	static Game* instance;

	Game();
	Game(Game& const) = delete;
	Game& operator=(Game&) = delete;
	//-------------------
};
