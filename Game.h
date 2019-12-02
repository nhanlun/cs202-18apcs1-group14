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
	void load();
	void save();
	void play();

	void settings();

private:
	Screen sc;

	std::vector<Level*> levels;
	int currentLevel;
	Color playerColor;
	State gameState;
};

#endif