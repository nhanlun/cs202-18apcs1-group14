#include "Player.h"
#include "Light.h"
#include "Dinosaur.h"
#include "Screen.h"
#include "Car.h"
#include "Bird.h"
#include "Truck.h"
#include <conio.h>

int main() 
{
	yaosu::setWindow();
	yaosu::fixConsoleWindow();
	yaosu::hideCursor();
	Screen sc;

	sc.splashScreen();
	system("cls");
	yaosu::color(int(Color::DEFAULT));

	Dinosaur dinoA(0, 20);
	dinoA.display(Direction::LEFT, sc, Color::GREEN);
	while (true)
	{
		int inp = _getch();
		if (inp == 27) break;
		else if (inp == 'm')
		{
			dinoA.move(Direction::LEFT, sc, Color::GREEN);
		}
	}
	return 0;
}