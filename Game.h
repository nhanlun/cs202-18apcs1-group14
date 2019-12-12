#ifndef GAME_H_
#define GAME_H_

#include "Level.h"
#include <vector>
#include "Support.h"
#include <MMSystem.h>

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void initGame();
	void loadGame();
	bool load(int saveSlot);
	void save(int saveSlot);
	void play(bool newGame);
	void settings();
	void changeColor();
	void changeDifficulty();
	bool createSettingFile();
	bool loadSettingFile();
	bool saveSettingFile();

	Screen sc;

	std::vector<Level*> levels;
	int currentLevel;
	bool sound; // if sound is true: music is on
	Difficulty difficulty;
	Color playerColor;
	State gameState;
};

#endif