#include "Car.h"

Car::Car() : Obstacle(16, 4)
{
	figR.push_back("    ______        ");
	figR.push_back(" __/   |##\\___    ");
	figR.push_back("[/ _ \\====/ _ \\]");
	figR.push_back(" \\___/    \\___/ ");

	figL.push_back("      _______    ");
	figL.push_back("  ___/##|   \\__  ");
	figL.push_back("[/ _ \\====/ _ \\]");
	figL.push_back(" \\___/    \\___/ ");
}

Car::Car(int x, int y):Obstacle(x,y,16,4)
{
	figR.push_back("    ______        ");
	figR.push_back(" __/   |##\\___    ");
	figR.push_back("[/ _ \\====/ _ \\]");
	figR.push_back(" \\___/    \\___/ ");

	figL.push_back("      ______    ");
	figL.push_back("  ___/##|   \\__  ");
	figL.push_back("[/ _ \\====/ _ \\]");
	figL.push_back(" \\___/    \\___/ ");
}

void Car::display(Direction dir, const Screen & sc)
{
	std::string line1, line2, line3, line4;

	if (dir == Direction::LEFT)
	{
		int offset = sc.offset(x, Direction::LEFT);

		line1 = figL[0].substr(offset, width - offset);
		line2 = figL[1].substr(offset, width - offset);
		line3 = figL[2].substr(offset, width - offset);
		line4 = figL[3].substr(offset, width - offset);
	}
	else
	{
		int offset = sc.offset(x + width, Direction::RIGHT);

		line1 = figR[0].substr(0, width - offset);
		line2 = figR[1].substr(0, width - offset);
		line3 = figR[2].substr(0, width - offset);
		line4 = figR[3].substr(0, width - offset);
	}

	int row = y, col = max(0, x);
	yaosu::gotoXY(col, row);
	std::cout << line1 << '\n';
	yaosu::gotoXY(x, row + 1);
	std::cout << line2 << '\n';
	yaosu::gotoXY(x, row + 2);
	std::cout << line3 << '\n';
	yaosu::gotoXY(x, row + 3);
	std::cout << line4 << '\n';
}


