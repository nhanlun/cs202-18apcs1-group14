#include "Player.h"
#include "Light.h"
#include <conio.h>

int main() 
{
	yaosu::setWindow();
	yaosu::fixConsoleWindow();
	yaosu::hideCursor();

	People yenCao;
	Light ngaTuHangXanh(50, 0, false);

	yenCao.display();
	ngaTuHangXanh.display();

	while (true) 
	{
		char inp = _getch();
		if (inp == 27) break;
		else switch (inp) {
		case 'w':
			yenCao.move(Direction::UP);
			break;
		case 'a':
			yenCao.move(Direction::LEFT);
			break;
		case 's':
			yenCao.move(Direction::DOWN);
			break;
		case 'd':
			yenCao.move(Direction::RIGHT);
			break;
		default:;
		}
	}
	return 0;
}