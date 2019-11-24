#ifndef PLAYER_H_
#define PLAYER_H_

#include "Support.h"
#include "Screen.h"
#include "Obstacle.h"
#include <ctype.h>

class Player
{
public:
	Player();
	Player(int _x, int _y);

	void move(Direction dir, const Screen& sc);
	void display();
	bool isAlive();
	bool isImpact(Obstacle* obstacle) const;

	void play(const Screen& sc, std::mutex* mtx);

private:
	void hide();

	int x, y; //center of 3x3
	bool alive;
};

#endif