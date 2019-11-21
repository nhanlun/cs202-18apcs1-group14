#include "Player.h"
#include <iostream>

People::People() : x(1), y(1), alive(true) {}

People::People(int _x, int _y) : x(_x), y(_y), alive(true) {}

void People::display()
{
	yaosu::gotoXY(x - 1, y - 1);
	std::cout << " O ";
	yaosu::gotoXY(x - 1, y);
	std::cout << '/' << char(219) << '\\';
	yaosu::gotoXY(x - 1, y + 1);
	std::cout << '/' << ' ' << '\\';
}

void People::hide()
{
	yaosu::gotoXY(x - 1, y - 1);
	std::cout << "   ";
	yaosu::gotoXY(x - 1, y);
	std::cout << "   ";
	yaosu::gotoXY(x - 1, y + 1);
	std::cout << "   ";
}

void People::move(Direction dir, const Screen& sc)
{
	hide();

	switch (dir)
	{
	case Direction::UP:
		if (sc.inScreen(x, y - 5)) y -= 4;
		break;
	case Direction::LEFT:
		if (sc.inScreen(x - 4, y)) x -= 3;
		break;
	case Direction::DOWN:
		if (sc.inScreen(x, y + 5)) y += 4;
		break;
	case Direction::RIGHT:
		if (sc.inScreen(x + 4, y)) x += 3;
		break;
	default:;
	}

	display();
}

bool People::isAlive()
{
	return alive;
}