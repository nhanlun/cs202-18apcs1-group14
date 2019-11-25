#include "Player.h"
#include "Light.h"
#include "Dinosaur.h"
#include "Screen.h"
#include "Car.h"
#include "Bird.h"
#include "Truck.h"
#include "Lane.h"
#include "Level.h"
#include <conio.h>

int main() 
{
	srand(time(NULL));
	Screen sc;
	Level level(10, sc);
	level.run(sc);
	return 0;
}