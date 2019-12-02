#ifndef GAME_H_
#define GAME_H_

#include "Level.h"
#include <vector>
#include "Support.h"
#include <MMSystem.h>

class Game
{
public:
	Game() = default;
	~Game();

	void run();

private:
	void initGame();
	void load();
	void save();
	void play();

	Screen sc;

	std::vector<Level*> levels;
	int currentLevel;
	State gameState;
};

#endif