#include "Obstacle.h"

Obstacle::Obstacle(int w, int h) : x(0), y(0), width(w), height(h) {}

Obstacle::Obstacle(int _x, int _y, int w, int h) : x(_x), y(_y), width(w), height(h) {}

Obstacle::~Obstacle() {}

void Obstacle::move(Direction dir, const Screen& sc)
{
	if (dir == Direction::LEFT && sc.inScreen(x + width - 1, y))
	{
		hide(dir);
		--x;
	}
	else if (dir == Direction::RIGHT && sc.inScreen(x + 1, y))
	{
		hide(dir);
		++x;
	}

	display(dir, sc);
}

void Obstacle::hide(Direction dir)
{
	int column = x;
	if (dir == Direction::LEFT) column += width - 1;

	for (int row = y; row < y + height; ++row)
		yaosu::printXY(column, row, ' ');
}

bool Obstacle::isImpact(int playerX, int playerY)
{
	return (x - 1 <= playerX && playerX <= x + width &&
		y - 1 <= playerY && playerY <= y + height);
}