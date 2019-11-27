#include "Obstacle.h"

Obstacle::Obstacle(int w, int h) : x(0), y(0), width(w), height(h) {}

Obstacle::Obstacle(int _x, int _y, int w, int h) : x(_x), y(_y), width(w), 
	height(h) {}

Obstacle::~Obstacle() {}

void Obstacle::move(Direction dir, const Screen& sc, Color color)
{
	hide(dir, sc);
	display(dir, sc, color);
	if (dir == Direction::LEFT) --x;
	else if (dir == Direction::RIGHT) ++x;
}

void Obstacle::hide(Direction dir, const Screen& sc)
{
	//Choose column to delete
	int column = -1;
	if (dir == Direction::LEFT && sc.inScreen(x + width, y))
		column = x + width;
	else if (dir == Direction::RIGHT && sc.inScreen(x - 1, y))
		column = x - 1;
	if (column < 0) return;

	//Delete column
	for (int row = y; row < y + height; ++row)
		yaosu::printXY(column, row, ' ');
}

bool Obstacle::isImpact(int playerX, int playerY, Direction dir)
{
	if (dir == Direction::LEFT)
		return (x - 1 < playerX && playerX - 2 < x + width &&
			y - 1 < playerY && playerY < y + height);
	return (x - 3 < playerX && playerX < x + width && 
		y - 1 < playerY && playerY < y + height);
}

bool Obstacle::outOfScreen(Direction dir, const Screen& sc)
{
	if (dir == Direction::LEFT) return (x + width < sc.getLeftBorder());
	return (x - 1 > sc.getRightBorder());
}

bool Obstacle::isImpact(int pos)
{
	if (pos + 1 < x || pos - 1 > x + width - 1) return false;
	return true;
}
