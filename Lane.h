#ifndef LANE_H_
#define LANE_H_

#include "Support.h"
#include "Light.h"
#include "Screen.h"
#include "Obstacle.h"
#include "Bird.h"
#include "Car.h"
#include "Truck.h"
#include "Dinosaur.h"

class Lane
{
public:
	Lane(Direction _dir, Type _type, int _delay, Color _code, int row, int speed);
	~Lane();
	void run(const Screen& sc, std::mutex* mtx); // run the clock and update all the object of that lane

private:
	Direction dir;
	int timeDelay;
	int time;
	int speed; // 1, 2, 3, 4
	int row;
	Type obsType;
	Light* trafficLight;
	Color obsColor;
	Screen sc;

	std::vector<Obstacle*> obstacles;
};

#endif