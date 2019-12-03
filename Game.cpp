#include "Game.h"

Game::Game()
{
	if (!loadSettingFile())
	{
		createSettingFile();
		loadSettingFile();
	}
	if (sound)
		yaosu::playThemeSong();
}

Game::~Game()
{
	saveSettingFile();
	for (auto& i : levels)
		delete i;
}

void Game::run()
{
	//sc.splashScreen();
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
			settings();
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
		levels[noLevel - 1] = new Level(noLevel, sc, gameState, playerColor);
	}
}

void Game::load()
{
}

void Game::save(int saveSlot)
{
	std::ofstream fo;

	switch (saveSlot)
	{
	case 0:
		fo.open("game1.txt");
		break;
	case 1:
		fo.open("game2.txt");
		break;
	case 2:
		fo.open("game3.txt");
		break;
	case 3:
		return;
	default:;
	}
	
	fo << currentLevel << '\n';
	for (auto& i : levels)
		i->save(fo);
	fo.close();
	sc.saveSuccessfully();
}

void Game::play()
{
	system("cls");
	sc.runScreen();
	initGame();
	while (currentLevel < (int)levels.size())
	{
		sc.levelDisplay(currentLevel);
		int saveSlot = 0;
		levels[currentLevel]->run(sc, saveSlot);

		if (gameState != State::WIN)
		{
			if (gameState == State::SAVE) save(saveSlot);
			break;
		}

		++currentLevel;
	}
}

void Game::settings()
{
	int action = sc.settingsMenu();
	while (1)
	{
		switch (action)
		{
		case 0:
			if (sound)
			{
				sound = false;
				yaosu::stopThemeSong();
			}
			else
			{
				sound = true;
				yaosu::playThemeSong();
			}
			break;
		case 1:
			changeColor();
			break;
		case 2:
			return;
		default:;
		}
		action = sc.settingsMenu();
	}
}

void Game::changeColor()
{
	int action = sc.colorMenu();
	if (action != -1) playerColor = Color(action);
}

bool Game::createSettingFile()
{
	std::ofstream fo;
	fo.open("Setting.cfg");
	if (!fo.is_open())
		return false;
	fo << 1 << '\n';
	fo << (int)Color::DEFAULT << '\n';
	fo.close();
	return true;
}

bool Game::loadSettingFile()
{
	std::ifstream fin;
	fin.open("Setting.cfg");
	if (!fin.is_open())
		return false;
	fin >> sound;
	int color; 
	fin >> color;
	playerColor = Color(color);
	return true;
}

bool Game::saveSettingFile()
{
	std::ofstream fo;
	fo.open("Setting.cfg");
	if (!fo.is_open())
		return false;
	fo << sound<<'\n';
	fo << (int)playerColor << '\n';
}
