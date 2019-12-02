#include "Screen.h"
#include <iostream>
#include <conio.h>
#include <string>

Screen::Screen()
{
	yaosu::setWindow();
	yaosu::fixConsoleWindow();
	yaosu::hideCursor();
}

bool Screen::inScreen(int x, int y) const
{
	return (x >= leftBorder && x <= rightBorder && y >= topBorder && y <= botBorder);
}

int Screen::offset(int x, Direction dir) const
{
	if (dir == Direction::LEFT) return max(0, leftBorder - x);
	return max(0, x - rightBorder - 1);
}

void Screen::splashScreen()
{
	using yaosu::gotoXY;
	using yaosu::color;
	using std::cout;

	drawBorder();
	
	int x = 120;

	drawCrossyRoad(x, 10);

	color(14);

	gotoXY(97, 24); cout << "   Created by"; Sleep(x);
	gotoXY(97, 25); cout << "Nguyen Thanh Nhan"; Sleep(x);
	gotoXY(97, 26); cout << " Dang Khanh Mai"; Sleep(x);
	gotoXY(97, 27); cout << "  Tang Loi Phat"; Sleep(x);

	color(11);
	gotoXY(41, 22); cout << "    ______        ";
	gotoXY(41, 23); cout << " __/   |##\\___    ";
	gotoXY(41, 24); cout << "[/ _ \\====/ _ \\]";
	gotoXY(41, 25); cout << " \\___/    \\___/ "; 
	Sleep(x);

	color(11);
	gotoXY(155, 22); cout << " __           ";
	gotoXY(155, 23); cout << "(_^\\-^^^-.    ";
	gotoXY(155, 24); cout << "  \\       \\__ ";
	gotoXY(155, 25); cout << "   |_|-|_|.__>";
	Sleep(x);

	x = 80;
	for (int i = 0; i < 6; ++i)
	{
		Sleep(x);
		if (i % 2)
			drawCrossyRoad(x, 10);
		else
			drawCrossyRoad(x, 15);
	}

	gotoXY(93, 32); 
	system("pause");
}

int Screen::menuScreen()
{
	system("cls");
	using yaosu::color;
	using yaosu::gotoXY;
	using std::cout;

	drawBorder();
	drawCrossyRoad(0, 10);

	color(11);
	gotoXY(41, 22); cout << "    ______        ";
	gotoXY(41, 23); cout << " __/   |##\\___    ";
	gotoXY(41, 24); cout << "[/ _ \\====/ _ \\]";
	gotoXY(41, 25); cout << " \\___/    \\___/ ";

	color(11);
	gotoXY(155, 22); cout << " __           ";
	gotoXY(155, 23); cout << "(_^\\-^^^-.    ";
	gotoXY(155, 24); cout << "  \\       \\__ ";
	gotoXY(155, 25); cout << "   |_|-|_|.__>";

	gotoXY(97, 24); cout << "                    "; 
	gotoXY(97, 25); cout << "                    ";
	gotoXY(97, 26); cout << "                    "; 
	gotoXY(97, 27); cout << "                    "; 

	gotoXY(102, 24); cout << "New game";
	gotoXY(102, 25); cout << "Load game";
	gotoXY(102, 26); cout << "Settings";
	gotoXY(102, 27); cout << "Exit";

	displayCursor();
	int cur = 24;
	int option[] = { 0, 1, 2, 3 };
	while (1)
	{
		if (_kbhit())
		{
			char cmd = _getch();
			switch (cmd)
			{
			case 'w':
				moveCursor(-1, cur, 4);
				break;
			case 's':
				moveCursor(1, cur, 4);
				break;
			case ' ':
				return option[cur - 24];
			default:
				break;
			}
		}
	}
}

int Screen::settingsMenu()
{
	system("cls");
	using yaosu::color;
	using yaosu::gotoXY;
	using std::cout;

	drawBorder();
	drawCrossyRoad(0, 10);

	color(11);
	gotoXY(41, 22); cout << "    ______        ";
	gotoXY(41, 23); cout << " __/   |##\\___    ";
	gotoXY(41, 24); cout << "[/ _ \\====/ _ \\]";
	gotoXY(41, 25); cout << " \\___/    \\___/ ";

	color(11);
	gotoXY(155, 22); cout << " __           ";
	gotoXY(155, 23); cout << "(_^\\-^^^-.    ";
	gotoXY(155, 24); cout << "  \\       \\__ ";
	gotoXY(155, 25); cout << "   |_|-|_|.__>";

	gotoXY(97, 24); cout << "                    ";
	gotoXY(97, 25); cout << "                    ";
	gotoXY(97, 26); cout << "                    ";
	gotoXY(97, 27); cout << "                    ";

	gotoXY(102, 24); cout << "Music On/Off";
	gotoXY(102, 25); cout << "Player Color";
	gotoXY(102, 26); cout << "Back";

	displayCursor();
	int cur = 24;
	int option[] = { 0, 1, 2 };
	while (1)
	{
		if (_kbhit())
		{
			char cmd = _getch();
			switch (cmd)
			{
			case 'w':
				moveCursor(-1, cur, 3);
				break;
			case 's':
				moveCursor(1, cur, 3);
				break;
			case ' ':
				return option[cur - 24];
			default:
				break;
			}
		}
	}
}

void Screen::levelDisplay(int noLevel)
{
	yaosu::printCenter(rightBorder, width, "Level: " + std::to_string(noLevel+1), 18);
}

void Screen::runScreen() const
{
	yaosu::printCenter(rightBorder, width, "TUTORIAL", 20);
	yaosu::printCenter(rightBorder, width, "------------", 21);
	yaosu::printCenter(rightBorder, width, "W, A, S, D: Move", 23);
	yaosu::printCenter(rightBorder, width, "P: Pause Game ", 25);
	yaosu::printCenter(rightBorder, width, "                      ", 27);
}

void Screen::pauseScreen() const
{
	yaosu::printCenter(rightBorder, width, "TUTORIAL", 20);
	yaosu::printCenter(rightBorder, width, "------------", 21);
	yaosu::printCenter(rightBorder, width, "  S: Save Game  ", 23);
	yaosu::printCenter(rightBorder, width, "R: Resume Game", 25);
	yaosu::printCenter(rightBorder, width, "ESC: Back To Main Menu", 27);
}

Light* Screen::lightFactory(Direction dir, int row) const
{
	if (dir == Direction::LEFT) return new Light(leftBorder, row - 1, false);
	return new Light(rightBorder, row - 1, false);
}

int Screen::getLeftBorder() const
{
	return leftBorder;
}

void Screen::displayMap() const
{
	system("cls");
	yaosu::color(15);
	char pavement = 177;
	int row = 4;
	
	yaosu::gotoXY(leftBorder, row);
	for (int i = leftBorder; i <= rightBorder; ++i)
		std::cout << pavement;
	for (int i = 1; i <= 4; ++i)
	{
		++row;
		yaosu::gotoXY(leftBorder, row);
		std::cout << pavement;
		yaosu::gotoXY(rightBorder, row);
		std::cout << pavement;
	}
	++row;
	yaosu::gotoXY(leftBorder, row);
	for (int i = leftBorder; i <= rightBorder; ++i)
		std::cout << pavement;

	for (int j = 1; j< 4; ++j)
	{
		row += 7;
		yaosu::gotoXY(leftBorder, row);
		for (int i = leftBorder; i <= rightBorder; ++i)
		{
			if (i % 2)
				std::cout << '_';
			else
				std::cout << ' ';
		}
	}
	row += 8;

	
	yaosu::gotoXY(leftBorder, row);
	for (int i = leftBorder; i <= rightBorder; ++i)
		std::cout << pavement;
	for (int i = 1; i <= 4; ++i)
	{
		++row;
		yaosu::gotoXY(leftBorder, row);
		std::cout << pavement;
		yaosu::gotoXY(rightBorder, row);
		std::cout << pavement;
	}
	++row;
	yaosu::gotoXY(leftBorder, row);
	for (int i = leftBorder; i <= rightBorder; ++i)
		std::cout << pavement;
}

int Screen::getRightBorder() const
{
	return rightBorder;
}


void Screen::eraseMap() const
{
	std::string blankLine(rightBorder - leftBorder + 1, ' ');
	for (int row = topBorder; row <= botBorder; ++row)
	{
		yaosu::gotoXY(leftBorder, row);
		std::cout << blankLine;
	}
}

void Screen::eraseRightPanel() const
{
	std::string blankLine(width - rightBorder - 1, ' ');
	for (int row = 0; row < height; ++row)
	{
		yaosu::gotoXY(rightBorder + 1, row);
		std::cout << blankLine;
	}
}

void Screen::displayCursor()
{
	yaosu::gotoXY(98, 24); std::cout << '>';
}

void Screen::moveCursor(int x, int& cur, int numOptions)
{
	using yaosu::gotoXY;
	using std::cout;
	int tmp = cur + x;
	if (tmp >= 24 && tmp < 24 + numOptions)
	{
		gotoXY(98, cur);
		cout << ' ';
		gotoXY(98, tmp);
		cout << '>';
		cur = tmp;
	}
}

void Screen::drawBorder()
{
	using yaosu::color;
	using yaosu::gotoXY;
	using std::cout;
	color(3);

	gotoXY(10, 5);
	cout << (char)201;
	for (int i = 11; i <= 201; ++i) cout << (char)205;
	cout << (char)187;

	for (int i = 6; i <= 43; ++i)
	{
		gotoXY(10, i);
		cout << (char)186;
		gotoXY(202, i);
		cout << (char)186;
	}

	gotoXY(10, 44);
	cout << (char)200;
	for (int i = 11; i <= 201; ++i) cout << (char)205;
	cout << (char)188;
}

void Screen::drawCrossyRoad(int x, int y)
{
	using yaosu::color;
	using yaosu::gotoXY;
	using std::cout;

	color(y);

	Sleep(x);
	gotoXY(49, 10); cout << " ------    -----       -----     ------   ------   \\     /          -----       -----          /\\         -----\\"; Sleep(x);
	gotoXY(49, 11); cout << "|         |     |     |     |   |        |          \\   /          |     |     |     |        /  \\        |     \\"; Sleep(x);
	gotoXY(49, 12); cout << "|         |     |     |     |   |        |           \\ /           |     |     |     |       /    \\       |      \\"; Sleep(x);
	gotoXY(49, 13); cout << "|         |-----      |     |    -----    -----       |            |-----      |     |      /------\\      |      |"; Sleep(x);
	gotoXY(49, 14); cout << "|         |     \\     |     |         |        |      |            |     \\     |     |     /        \\     |      /"; Sleep(x);
	gotoXY(49, 15); cout << "|         |      \\    |     |         |        |      |            |      \\    |     |    /          \\    |     /"; Sleep(x);
	gotoXY(49, 16); cout << " ------   |       \\    -----    ------   ------       |            |       \\    -----    /            \\   -----/"; Sleep(x);
}
