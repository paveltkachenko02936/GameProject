#pragma once

class AsteroidGenerator
{
public:
	AsteroidGenerator();
	~AsteroidGenerator();

	void init();

private:
	void spawnAsteroid();

	float spawnInterval;
};

