#include "Screen.h"

bool Screen::inScreen(int x, int y) const
{
	return (x >= 0 && x <= width && y >= 0 && y <= height);
}

int Screen::offset(int x, Direction dir) const
{
	if (dir == Direction::LEFT) return max(0, -x);
	return max(0, x - width);
}