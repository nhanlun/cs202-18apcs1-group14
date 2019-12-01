#ifndef SUPPORT_H_
#define SUPPORT_H_

#include "Windows.h"
#include <MMSystem.h>
#include <iostream>
#include <string>

enum class Direction { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3, Count };
enum class Type { CAR = 0, TRUCK = 1, DINOSAUR = 2, BIRD = 3, Count };
enum class Color 
{
	DEFAULT = 7, GREY = 8, BLUE = 9, GREEN = 10, CYAN = 11, 
	RED = 12, PINK = 13, YELLOW = 14, WHITE = 15
};
enum class Speed
{
	FAST = 1, AVERAGE = 2, SAFE = 3, SLOW = 4
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
	void printCenter(int left, int right, std::string content, int row, Color c = Color::DEFAULT);
	void playThemeSong();
	std::string getStringOf(Type t);// for debug purpose
	//void ambulance();
}

#endif