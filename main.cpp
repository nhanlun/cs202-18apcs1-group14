#include "Player.h"
#include "Light.h"
#include "Dinosaur.h"
#include "Bird.h"
#include <conio.h>

int main() 
{
	yaosu::setWindow();
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
	}
	return 0;
}