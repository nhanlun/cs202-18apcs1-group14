#ifndef PLAYER_H_
#define PLAYER_H_

#include "Support.h"

class People
{
public:
	People();

	void move(Direction dir);
	void display();
	bool isAlive();

private:
	void hide();

	int x, y;
	bool alive;
};

#endif