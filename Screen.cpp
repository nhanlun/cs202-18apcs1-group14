#include "Screen.h"

Screen::Screen()
{
	yaosu::setWindow();
	yaosu::fixConsoleWindow();
	yaosu::hideCursor();
}

bool Screen::inScreen(int x, int y) const
{
	return (x >= 0 && x <= width && y >= 0 && y <= height);
}

int Screen::offset(int x, Direction dir) const
{
	if (dir == Direction::LEFT) return max(0, -x);
	return max(0, x - width);
}

void Screen::splashScreen()
{
	yaosu::gotoXY(0, 40);
	for (int i = 1; i <= 170; ++i) std::cout << '.';
}
