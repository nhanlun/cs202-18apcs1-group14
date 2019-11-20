#ifndef SUPPORT_H_
#define SUPPORT_H_

#include <Windows.h>

enum class Direction { UP, LEFT, DOWN, RIGHT };

namespace yaosu
{
	const int DEFAULT = 7;
	const int RED = 12;
	const int GREEN = 10;

	void fixConsoleWindow();
	void gotoXY(short x, short y);
	void hideCursor();
	void color(int code);
	void printXY(short x, short y, char c, int colorCode);
}

#endif