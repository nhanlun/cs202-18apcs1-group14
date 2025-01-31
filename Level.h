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
	Level(int noLevel, Screen& sc, State& state, Color playerColor, Difficulty diff);
	~Level();

	void run(const Screen& sc, int& saveSlot);
	void save(std::ofstream& fo);
	void load(std::ifstream& fin);

private:
	void resetPlayer();
	void addThreadPlayer(std::vector<std::thread*>& vThread, const Screen& sc, int& saveSlot);
	void addThreadLanes(std::vector<std::thread*>& vThread, const Screen& sc, 
		unsigned& noLane);
	void runThreads(std::vector<std::thread*>& vThread);

	std::vector<Lane*> lanes;
	Player* player;
	State& gameState;

	std::mutex ioMtx;
	std::mutex stateMtx;
};

#endif
