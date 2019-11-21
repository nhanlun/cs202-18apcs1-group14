#ifndef PLAYER_H_
#define PLAYER_H_

#include "Support.h"
#include "Screen.h"

class People
{
public:
	People();
	People(int _x, int _y);

	void move(Direction dir, const Screen& sc);
	void display();
	bool isAlive();

private:
	void hide();

	int x, y; //center of 3x3
	bool alive;
};

#endif