#include "Player.h"
#include "Light.h"
#include "Dinosaur.h"
#include "Screen.h"
#include "Car.h"
#include "Bird.h"
#include "Truck.h"
#include "Lane.h"
#include <conio.h>

int main() 
{
	Screen sc;
	//sc.splashScreen();
	std::mutex* mtx = new std::mutex;
	Lane* tmp1 = new Lane(Direction::RIGHT, Type::BIRD, 15, Color::BLUE, 1, 1);
	Lane* tmp2 = new Lane(Direction::LEFT, Type::CAR, 50, Color::BLUE, 6, 2);
	std::thread t1(&Lane::run, tmp1, sc, mtx);
	std::thread t2(&Lane::run, tmp2, sc, mtx);
	t1.join();
	t2.join();
	delete tmp1;
	delete tmp2;
	delete mtx;
	return 0;
}