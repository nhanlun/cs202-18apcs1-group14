#include "Dinosaur.h"
#include <iostream>

Dinosaur::Dinosaur(int x, int y) : Obstacle(x, y, 14, 4), figL(4), figR(4)
{
	figL[0] = " __           ";
	figL[1] = "(_^\\-^^^-.    ";
	figL[2] = "  \\       \\__ ";
	figL[3] = "   |_|-|_|.__>";

	figR[0] = "           __ ";
	figR[1] = "    .-^^^-/^_)";
	figR[2] = " __/       /  ";
	figR[3] = "<__.|_|-|_|   ";
}

void Dinosaur::display(Direction dir, const Screen& sc, Color color)
{
	std::string line1, line2, line3, line4;
	
	if (dir == Direction::LEFT)
	{
		int offset = sc.offset(x, dir);
		line1 = figL[0].substr(offset, width - offset);
		line2 = figL[1].substr(offset, width - offset);
		line3 = figL[2].substr(offset, width - offset);
		line4 = figL[3].substr(offset, width - offset);	
	}
	else
	{
		int offset = sc.offset(x + width, dir);
		line1 = figR[0].substr(0, width - offset);
		line2 = figR[1].substr(0, width - offset);
		line3 = figR[2].substr(0, width - offset);
		line4 = figR[3].substr(0, width - offset);
	}

	yaosu::color(int(color));
	int row = y, col = max(0, x);
	yaosu::gotoXY(col, row);
	std::cout << line1;
	yaosu::gotoXY(col, row + 1);
	std::cout << line2;
	yaosu::gotoXY(col, row + 2);
	std::cout << line3;
	yaosu::gotoXY(col, row + 3);
	std::cout << line4;
	yaosu::color(int(Color::DEFAULT));
}