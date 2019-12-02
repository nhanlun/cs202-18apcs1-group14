#include "Game.h"

Game::~Game()
{
	for (auto& i : levels)
		delete i;
}

void Game::run()
{
	yaosu::playThemeSong();
	sc.splashScreen();
	int action = sc.menuScreen();
	while (1)
	{
		switch (action)
		{
		case 0:
			play();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			return;
		default:
			break;
		}
		action = sc.menuScreen();
	}
}

void Game::initGame()
{
	currentLevel = 0;
	gameState = State::RUN;
	for (auto& i : levels) delete i;
	levels.clear();

	levels.resize(10, nullptr);
	for (unsigned noLevel = 1; noLevel <= levels.size(); ++noLevel)
	{
		levels[noLevel - 1] = new Level(noLevel, sc, gameState);
	}
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

void Game::play()
{
	system("cls");
	sc.runScreen();
	initGame();
	while (currentLevel < (int)levels.size())
	{
		sc.levelDisplay(currentLevel);
		levels[currentLevel]->run(sc);

		if (gameState != State::WIN)
		{
			if (gameState == State::SAVE) save();
			break;
		}

		++currentLevel;
	}
}
