#include "Player.h"
#include "Light.h"
#include "Dinosaur.h"
#include "Screen.h"
#include "Car.h"
#include "Bird.h"
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
	/*Screen sc;
	Car c1(3,3);
	c1.display(Direction::LEFT, sc);
	Car c2(20, 3);
	c2.display(Direction::RIGHT, sc);
	while (true)
	{
		int key = _getch();
		if (key == 27)
			break;
		if (key == 'm')
		{
			c1.move(Direction::LEFT, sc);
			c2.move(Direction::RIGHT, sc);
		}
	}*/
	//c1.display(Direction::LEFT,sc);
	//system("pause");

	Screen screen;
	screen.splashScreen();
	return 0;
}