#include "Car.h"

Car::Car() : Obstacle(16, 4)
{
	figureR.push_back("    ______        ");
	figureR.push_back(" __/   |##\\___    ");
	figureR.push_back("[/ _ \\====/ _ \\]");
	figureR.push_back(" \\___/    \\___/ ");

	figureL.push_back("      _______    ");
	figureL.push_back("  ___/##|   \\__  ");
	figureL.push_back("[/ _ \\====/ _ \\]");
	figureL.push_back(" \\___/    \\___/ ");
}

Car::Car(int x, int y):Obstacle(x,y,16,4)
{
	figureR.push_back("    ______        ");
	figureR.push_back(" __/   |##\\___    ");
	figureR.push_back("[/ _ \\====/ _ \\]");
	figureR.push_back(" \\___/    \\___/ ");

	figureL.push_back("      ______    ");
	figureL.push_back("  ___/##|   \\__  ");
	figureL.push_back("[/ _ \\====/ _ \\]");
	figureL.push_back(" \\___/    \\___/ ");
}

void Car::display(Direction dir, const Screen & sc)
{
	if (dir == Direction::LEFT)
	{
		int offset = sc.offset(x, Direction::LEFT);

		std::string line1 = figureL[0].substr(offset, width - offset);
		std::string line2 = figureL[1].substr(offset, width - offset);
		std::string line3 = figureL[2].substr(offset, width - offset);
		std::string line4 = figureL[3].substr(offset, width - offset);

		int row = y, col = max(0, x);
		yaosu::gotoXY(col, row);
		std::cout << line1<< '\n';
		yaosu::gotoXY(x, row + 1);
		std::cout << line2 << '\n';
		yaosu::gotoXY(x, row + 2);
		std::cout << line3<< '\n';
		yaosu::gotoXY(x, row + 3);
		std::cout << line4 << '\n';

	}
	else
	{
		if (dir == Direction::RIGHT)
		{
			int offset = sc.offset(x + width, Direction::RIGHT);

			std::string line1 = figureR[0].substr(0, width - offset);
			std::string line2 = figureR[1].substr(0, width - offset);
			std::string line3 = figureR[2].substr(0, width - offset);
			std::string line4 = figureR[3].substr(0, width - offset);

			yaosu::gotoXY(x, y);
			std::cout << line1 << '\n';
			yaosu::gotoXY(x, y+1);
			std::cout << line2 << '\n';
			yaosu::gotoXY(x, y+2);
			std::cout << line3 << '\n';
			yaosu::gotoXY(x, y+3);
			std::cout << line4 << '\n';
		}
	}
}


