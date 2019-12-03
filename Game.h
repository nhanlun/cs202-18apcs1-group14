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
	void load();
	void save(int saveSlot);
	void play();
	void settings();
	void changeColor();
	bool createSettingFile();
	bool loadSettingFile();
	bool saveSettingFile();

	Screen sc;

	std::vector<Level*> levels;
	int currentLevel;
	bool sound; // if sound is true: music is on
	Color playerColor;
	State gameState;
};

#endif