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
	/*yaosu::setWindow();
	yaosu::fixConsoleWindow();
	yaosu::hideCursor();
	Screen sc;

	Bird maleBird(0, 0), femaleBird(213 - 4, 5);
	maleBird.display(Direction::RIGHT, sc);
	femaleBird.display(Direction::LEFT, sc);

	Dinosaur maleDino(0, 10), femaleDino(213 - 14, 15);
	maleDino.display(Direction::RIGHT, sc);
	femaleDino.display(Direction::LEFT, sc);

	while (true)
	{
		int inp = _getch();
		if (inp == 27) break;
		if (inp == 'm')
		{
			maleBird.move(Direction::RIGHT, sc);
			femaleBird.move(Direction::LEFT, sc);
			maleDino.move(Direction::RIGHT, sc);
			femaleDino.move(Direction::LEFT, sc);
		}
	}*/

	//Mai's testing zone
	Screen sc;
	Truck t1(3,3);
	t1.display(Direction::LEFT, sc);
	Truck t2(20, 3);
	t2.display(Direction::RIGHT, sc);
	while (true)
	{
		int key = _getch();
		if (key == 27)
			break;
		if (key == 'm')
		{
			t1.move(Direction::LEFT, sc);
			t2.move(Direction::RIGHT, sc);
		}
	}
	system("pause");

	Screen screen;
	screen.splashScreen();
	/*for (int i = 1; i <= 20; ++i)
	{
		yaosu::color(i);
		std::cout << "a\n";
	}*/
	// End of Mai's testing zone

	return 0;
}