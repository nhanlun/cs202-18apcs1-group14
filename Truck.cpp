#include "Truck.h"

Truck::Truck() :Obstacle(16, 4)
{
	char a = 196;
	std::string tmp = (char)218 + a + a + a + a + a + a + a + a + (char)191 + "____  ";
	figR.push_back(tmp);
	figR.push_back("|  ___   |___ \\ ");
	figR.push_back("|_/ _ \\==/ _ \\_]");
	figR.push_back("  \\___/  \\___/  ");

	tmp.clear();
	tmp = tmp + "  ____" + (char)218 + a + a + a + a + a + a + a + a + (char)191;
	figL.push_back(tmp);
	figL.push_back(" / ___|   ___  |");
	figL.push_back("[_/ _ \\==/ _ \\_|");
	figL.push_back("  \\___/  \\___/  ");
}

Truck::Truck(int x, int y):Obstacle(x,y,16,4)
{
	char a = 196;
	std::string tmp;
	tmp = tmp + (char)218 + a + a + a + a + a + a + a + a + (char)191 + "____  ";
	figR.push_back(tmp);
	figR.push_back("|  ___   |___ \\ ");
	figR.push_back("|_/ _ \\==/ _ \\_]");
	figR.push_back("  \\___/  \\___/  ");

	tmp.clear();
	tmp = tmp + "  ____" + (char)218 + a + a + a + a + a + a + a + a + (char)191;
	figL.push_back(tmp);
	figL.push_back(" / ___|   ___  |");
	figL.push_back("[_/ _ \\==/ _ \\_|");
	figL.push_back("  \\___/  \\___/  ");
}

void Truck::display(Direction dir, const Screen & sc, Color color)
{
	std::string line1, line2, line3, line4;
	if(dir == Direction::LEFT)
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

	yaosu::color(int(color));
	int row = y, col = max(0, x);
	yaosu::gotoXY(col, row);
	std::cout << line1 << '\n';
	yaosu::gotoXY(x, row + 1);
	std::cout << line2 << '\n';
	yaosu::gotoXY(x, row + 2);
	std::cout << line3 << '\n';
	yaosu::gotoXY(x, row + 3);
	std::cout << line4 << '\n';
	yaosu::color(int(Color::DEFAULT));
}
