#ifndef SUPPORT_H_
#define SUPPORT_H_

#include <Windows.h>
#include <iostream>
#include <conio.h>

enum class Direction { UP, LEFT, DOWN, RIGHT };
enum class Type { CAR, TRUCK, DINOSAUR, BIRD };
enum class Color {
	DEFAULT = 7, GREY = 8, BLUE = 9, GREEN = 10, CYAN = 11, 
	RED = 12, PINK = 13, YELLOW = 14, WHITE = 15
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