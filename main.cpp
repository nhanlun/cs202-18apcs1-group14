#include "Game.h"
#include "Ambulance.h"
int main()
{
	srand(time(NULL));
	Game game;
	game.run();
	/*Ambulance a(10, 5, Direction::LEFT);
	a.test(Direction::LEFT);*/

	//system("pause");
	return 0;
}