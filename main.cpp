#include "Player.h"
#include "Light.h"
#include "Dinosaur.h"
#include <conio.h>

int main() 
{
	yaosu::setWindow();
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
	}
	return 0;
}