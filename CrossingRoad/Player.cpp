#include "Player.h"
#include <iostream>

People::People() : x(1), y(1), alive(true) {}

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

void People::move(Direction dir)
{
	hide();

	switch (dir)
	{
	case Direction::UP:
		if (y >= 4) y -= 4;
		break;
	case Direction::LEFT:
		if (x >= 1) --x;
		break;
	case Direction::DOWN:
		y += 4;
		break;
	case Direction::RIGHT:
		++x;
		break;
	default:;
	}

	display();
}

bool People::isAlive()
{
	return alive;
}