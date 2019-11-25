#pragma once
#ifndef Level_h
#define Level_h

#include "Support.h"
#include "Player.h"
#include "Lane.h"
#include <random>
#include <ctime>

class Level
{
public:
	Level(int noLevel, Screen& sc);
	~Level();

	void run(const Screen& sc);

private:
	std::vector<Lane*> lanes;
	Player* player;
	State gameState;

	std::mutex ioMtx;
	std::mutex stateMtx;
};

#endif
