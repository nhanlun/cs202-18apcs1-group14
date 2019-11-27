#include "Game.h"

Game::Game():levels(10),currentLevel(0),gameState(State::RUN)
{
	//Random the level
	for (unsigned noLevel = 1; noLevel <= levels.size(); ++noLevel)
	{
		levels[noLevel - 1] = new Level(noLevel, sc, gameState);
	}
}

Game::~Game()
{
	for (auto& i : levels)
		delete i;
}

void Game::run()
{
	//yaosu::playThemeSong();
	//sc.splashScreen();
	while (currentLevel < levels.size() && gameState != State::LOSE && gameState != State::STOP)
	{
		levels[currentLevel]->run(sc);
		++currentLevel;
	}
}
