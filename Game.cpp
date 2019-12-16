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
	sc.splashScreen();
	int action = sc.menuScreen();
	while (1)
	{
		switch (action)
		{
		case 0:
			play(true);
			break;
		case 1:
			loadGame();
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
		levels[noLevel - 1] = new Level(noLevel, sc, gameState, playerColor, difficulty);
	}
}

void Game::loadGame()
{
	int action = sc.loadScreen();
	while (action != 3)
	{
		bool loaded = load(action);
		if (!loaded)
		{
			sc.notiCannotLoad();
		}
		else
		{
			play(false);
			return;
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		action = sc.loadScreen();
	}
}

bool Game::load(int saveSlot)
{
	std::ifstream fin;

	switch (saveSlot)
	{
	case 0:
		fin.open("game1.bin", std::ios::binary);
		break;
	case 1:
		fin.open("game2.bin", std::ios::binary);
		break;
	case 2:
		fin.open("game3.bin", std::ios::binary);
		break;
	default:;
	}

	if (!fin.is_open())
		return false;

	gameState = State::RUN;
	if (levels.empty())
	{
		levels.resize(10, nullptr);
		for (unsigned noLevel = 1; noLevel <= levels.size(); ++noLevel)
		{
			levels[noLevel - 1] = new Level(noLevel, sc, gameState, playerColor, difficulty);
		}
	}
	fin.read((char*)& currentLevel, 4);
	for (auto& i : levels)
		i->load(fin);
	fin.close();
	return true;
}

void Game::save(int saveSlot)
{
	std::ofstream fo;

	switch (saveSlot)
	{
	case 0:
		fo.open("game1.bin", std::ios::binary);
		break;
	case 1:
		fo.open("game2.bin", std::ios::binary);
		break;
	case 2:
		fo.open("game3.bin", std::ios::binary);
		break;
	case 3:
		return;
	default:;
	}
	
	//fo << currentLevel << '\n';
	fo.write((char*)& currentLevel, 4);
	for (auto& i : levels)
		i->save(fo);
	fo.close();
	sc.saveSuccessfully();
}

void Game::play(bool newGame)
{
	system("cls");
	sc.runScreen();
	if (newGame) initGame();

	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		sc.levelDisplay(currentLevel);
		int saveSlot = -1;
		levels[currentLevel]->run(sc, saveSlot);

		if (gameState != State::WIN)
		{
			if (gameState == State::LOSE)
			{
				if (sound)
					yaosu::playThemeSong();
				if (!stopPlaying())
				{
					system("cls");
					sc.runScreen();
					continue;
				}
			}

			if (gameState == State::SAVE) save(saveSlot);
			break;
		}
		
		sc.notiLevelUp();
		++currentLevel;
		if (currentLevel == int(levels.size()))
		{
			if (sc.winScreen())
			{
				currentLevel = 0;
				system("cls");
				sc.runScreen();
			}
			else
				return;
		}
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
			changeDifficulty();
			break;
		case 3:
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

void Game::changeDifficulty()
{
	int action = sc.difficultyMenu();
	switch (action) 
	{
	case 0:
		difficulty = Difficulty::EASY;
		break;
	case 1:
		difficulty = Difficulty::MEDIUM;
		break;
	case 2:
		difficulty = Difficulty::HARD;
		break;
	case 3:
		return;
	default:;
	}
}

bool Game::createSettingFile()
{
	std::ofstream fo;
	fo.open("Setting.bin", std::ios::binary);

	if (!fo.is_open())
		return false;

	bool tmp = 1;
	fo.write((char*)& tmp, 1);

	int color = (int)Color::DEFAULT;
	fo.write((char*)& color, 4);

	int diff = (int)Difficulty::MEDIUM;
	fo.write((char*)& diff, 4);
	fo.close();
	return true;
}

bool Game::loadSettingFile()
{
	std::ifstream fin;
	fin.open("Setting.bin", std::ios::binary);

	if (!fin.is_open())
		return false;

	fin.read((char*)& sound, 1);

	int tmp;
	fin.read((char*)& tmp, 4);
	playerColor = (Color)(tmp);

	fin.read((char*)& tmp, 4);
	difficulty = (Difficulty)(tmp);
	fin.close();
	return true;
}

bool Game::saveSettingFile()
{
	std::ofstream fo;
	fo.open("Setting.bin", std::ios::binary);

	if (!fo.is_open())
		return false;

	fo.write((char*)& sound, 1);

	int color = (int)playerColor;
	fo.write((char*)& color, 4);

	int diff = (int)difficulty;
	fo.write((char*)& diff, 4);

	fo.close();
	return true;
}

bool Game::stopPlaying()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	return (sc.gameOverMenu() == 1); // refuse to replay
}