#include "Car.h"

Car::Car()
{
	figureR.push_back("    ______");
	figureR.push_back(" __/____##\\___");
	figureR.push_back("[/ _ \\====/ _ \\]");
	figureR.push_back(" \\___/    \\___/");

	figureL.push_back("      ______");
	figureL.push_back("  ___/##|   \\__");
	figureL.push_back("[/ _ \\====/ _ \\]");
	figureL.push_back(" \\___/    \\___/");
}

Car::Car(int x, int y):Obstacle(x,y)
{
	figureR.push_back("    ______");
	figureR.push_back(" __/____##\\___");
	figureR.push_back("[/ _ \\====/ _ \\]");
	figureR.push_back(" \\___/    \\___/");
}

void Car::display()
{
	yaosu::gotoXY(x, y);
	std::cout << figureR[0]<< '\n';
	yaosu::gotoXY(x, y + 1);
	std::cout << figureR[1] << '\n';
	yaosu::gotoXY(x, y + 2);
	std::cout << figureR[2] << '\n';
	yaosu::gotoXY(x, y + 3);
	std::cout << figureR[3] << '\n';
}
