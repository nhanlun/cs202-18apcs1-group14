#include "Player.h"
#include "Light.h"
#include "Dinosaur.h"
#include "Screen.h"
#include "Car.h"
#include <conio.h>

int main() 
{
	/*yaosu::setWindow();
	yaosu::fixConsoleWindow();
	yaosu::hideCursor();
	Screen sc;

	Dinosaur maleDino(0, 15), femaleDino(198, 15);
	maleDino.display(Direction::RIGHT, sc);
	femaleDino.display(Direction::LEFT, sc);

	while (true)
	{
		int inp = _getch();
		if (inp == 27) break;
		if (inp == 'm')
		{
			maleDino.move(Direction::RIGHT, sc);
			femaleDino.move(Direction::LEFT, sc);
		}
	}*/

	//Mai's testing zone
	yaosu::setWindow();
	yaosu::fixConsoleWindow();
	yaosu::hideCursor();
	Screen sc;
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
	}
	//c1.display(Direction::LEFT,sc);
	system("pause");
	return 0;
}