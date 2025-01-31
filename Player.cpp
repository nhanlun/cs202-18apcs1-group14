#include "Player.h"
#include <iostream>
#include <conio.h>

Player::Player() : x(1), y(1), alive(true), color(Color::DEFAULT) {}

Player::Player(int _x, int _y, Color _color) : x(_x), y(_y), alive(true), color(_color) {}

void Player::display()
{
	yaosu::color(int(color));
	yaosu::gotoXY(x - 1, y - 1);
	std::cout << " O ";
	yaosu::gotoXY(x - 1, y);
	std::cout << '/' << char(219) << '\\';
	yaosu::gotoXY(x - 1, y + 1);
	std::cout << '/' << ' ' << '\\';
	yaosu::color(int(Color::DEFAULT));
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

void Player::play(const Screen& sc, std::mutex* ioMtx, State& state, int& saveSlot)
{
	while (state == State::RUN || state == State::PAUSE)
	{
		if (state == State::RUN) runMode(sc, ioMtx, state);
		else pauseMode(sc, ioMtx, state, saveSlot);
		Sleep(100);
	}
}

void Player::runMode(const Screen& sc, std::mutex* ioMtx, State& state)
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
		case 'P':
			sc.pauseScreen();
			state = State::PAUSE;
			break;
		default:;
		}
		ioMtx->unlock();
	}
}

void Player::pauseMode(const Screen& sc, std::mutex* ioMtx, State& state, int& saveSlot)
{
	if (_kbhit())
	{
		char cmd = toupper(_getch());
		ioMtx->lock();
		switch (cmd)
		{
		case 'S':
			saveMode(sc, ioMtx, saveSlot);
			if (saveSlot != -1) state = State::SAVE;
			else sc.eraseRightPanel(29, 34);
			break;
		case 'R':
			sc.runScreen();
			state = State::RUN;
			break;
		case 27:
			state = State::STOP;
			break;
		default:;
		}
		ioMtx->unlock();
	}
}

void Player::saveMode(const Screen& sc, std::mutex* ioMtx, int& saveSlot)
{
	int action = sc.saveScreen();
	if (action != 3) saveSlot = action;
}

void Player::resetBottomPavement()
{
	y = 41;
}

void Player::resetLevel()
{
	x = 50;
	y = 41;
}

int Player::getPositionX() const
{
	return x;
}
