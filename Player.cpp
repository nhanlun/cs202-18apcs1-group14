#include "Player.h"
#include <iostream>

Player::Player() : x(1), y(1), alive(true) {}

Player::Player(int _x, int _y) : x(_x), y(_y), alive(true) {}

void Player::display()
{
	yaosu::gotoXY(x - 1, y - 1);
	std::cout << " O ";
	yaosu::gotoXY(x - 1, y);
	std::cout << '/' << char(219) << '\\';
	yaosu::gotoXY(x - 1, y + 1);
	std::cout << '/' << ' ' << '\\';
}

void Player::hide()
{
	yaosu::gotoXY(x - 1, y - 1);
	std::cout << "   ";
	yaosu::gotoXY(x - 1, y);
	std::cout << "   ";
	yaosu::gotoXY(x - 1, y + 1);
	std::cout << "   ";
}

void Player::move(Direction dir, const Screen& sc)
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

bool Player::isAlive()
{
	return alive;
}

bool Player::isImpact(Obstacle* obstacle) const
{
	return obstacle->isImpact(x, y);
}