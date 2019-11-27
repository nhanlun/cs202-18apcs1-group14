#include "Player.h"
#include <iostream>
#include <conio.h>

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
		if (sc.inScreen(x, y - 8)) y -= 7;
		break;
	case Direction::LEFT:
		if (sc.inScreen(x - 4, y)) x -= 2;
		break;
	case Direction::DOWN:
		if (sc.inScreen(x, y + 8)) y += 7;
		break;
	case Direction::RIGHT:
		if (sc.inScreen(x + 4, y)) x += 2;
		break;
	default:;
	}

	display();
}

bool Player::isAlive()
{
	return alive;
}

bool Player::isImpact(Obstacle* obstacle, Direction dir) const
{
	return obstacle->isImpact(x, y, dir);
}

void Player::play(const Screen& sc, std::mutex* ioMtx, State& state)
{
	while (state == State::RUN)
	{
		if (_kbhit()) 
		{
			char cmd = toupper(_getch());
			ioMtx->lock();
			switch (cmd)
			{
			case 'W':
				move(Direction::UP, sc);
				if (y == 6) state = State::WIN;
				break;
			case 'S':
				move(Direction::DOWN, sc);
				break;
			case 'D':
				move(Direction::RIGHT, sc);
				break;
			case 'A':
				move(Direction::LEFT, sc);
				break;
			case 27:
				state = State::STOP;
				break;
			default:;
			}
			ioMtx->unlock();
		}

		Sleep(80);
	}
}

void Player::reset()
{
	y = 41;
}