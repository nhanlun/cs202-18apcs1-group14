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

	Light* l1 = sc.lightFactory(Direction::RIGHT, 10);
	Light* l2 = sc.lightFactory(Direction::LEFT, 10);

	l1->display();
	l2->display();

	delete l1;
	delete l2;
	return 0;
}