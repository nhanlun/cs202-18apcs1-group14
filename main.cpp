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
	Lane* tmp1 = new Lane(Direction::RIGHT, Type::BIRD, 1);
	Lane* tmp2 = new Lane(Direction::LEFT, Type::CAR, 6);
	std::thread t1(&Lane::run, tmp1, sc, mtx);
	std::thread t2(&Lane::run, tmp2, sc, mtx);

	Player* player = new Player(10, 13);
	std::thread t3(&Player::play, player, sc, mtx);

	t1.join();
	t2.join();
	t3.join();
	delete tmp1;
	delete tmp2;
	delete player;
	delete mtx;
	return 0;
}