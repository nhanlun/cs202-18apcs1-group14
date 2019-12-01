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
	sc.tutorialScreen();
	while (currentLevel < (int)levels.size())
	{
		sc.levelDisplay(currentLevel);
		levels[currentLevel]->run(sc);
		if (gameState == State::LOSE || gameState == State::STOP)
			break;
		++currentLevel;
	}
	save();
}

void Game::load()
{
}

void Game::save()
{
	std::cout << "Which file do you want to save? \n";
	int file; std::cin >> file;
	std::ofstream fo;

	switch (file)
	{
	case 1:
		fo.open("game1.txt");
		break;
	case 2:
		fo.open("game2.txt");
		break;
	case 3:
		fo.open("game3.txt");
		break;
	default:
		break;
	}
	
	fo << currentLevel << '\n';
	for (auto& i : levels)
		i->save(fo);
	fo.close();
}
