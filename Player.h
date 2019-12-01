#ifndef PLAYER_H_
#define PLAYER_H_

#include "Support.h"
#include "Screen.h"
#include "Obstacle.h"
#include <ctype.h>
#include <mutex>

class Player
{
public:
	Player();
	Player(int _x, int _y);

	void move(Direction dir, const Screen& sc);
	void display();
	bool isAlive();
	bool isImpact(Obstacle* obstacle, Direction dir) const;

	void play(const Screen& sc, std::mutex* ioMtx, State& state);
	void reset();

private:
	void hide();

	void runMode(const Screen& sc, std::mutex* ioMtx, State& state);
	void pauseMode(const Screen& sc, std::mutex* ioMtx, State& state);
	void saveMode(const Screen& sc, std::mutex* ioMtx, State& state);

	int x, y; //center of 3x3
	bool alive;
};

#endif