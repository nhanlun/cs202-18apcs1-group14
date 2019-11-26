#ifndef SUPPORT_H_
#define SUPPORT_H_

#include "Windows.h"
#include <iostream>

enum class Direction { UP, LEFT, DOWN, RIGHT, Count };
enum class Type { CAR, TRUCK, DINOSAUR, BIRD, Count };
enum class Color 
{
	DEFAULT = 7, GREY = 8, BLUE = 9, GREEN = 10, CYAN = 11, 
	RED = 12, PINK = 13, YELLOW = 14, WHITE = 15
};
enum class Speed
{
	FAST = 1, AVERAGE, SAFE, SLOW
};
enum class State
{
	RUN, STOP, PAUSE, WIN, LOSE
};

namespace yaosu
{
	void fixConsoleWindow();
	void gotoXY(short x, short y);
	void hideCursor();
	void color(int code);
	void printXY(short x, short y, char c, int colorCode = int(Color::DEFAULT));
	void setWindow();
}

#endif