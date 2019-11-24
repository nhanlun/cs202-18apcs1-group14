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
	Lane(Direction _dir, Type _type, int _row, int spawn = 100, int _speed = 10, 
		int _green = 100, int _red = 5000, Color _clr = Color::DEFAULT);
	~Lane();
	void run(const Screen& sc, std::mutex* mtx); // run the clock and update all the object of that lane

private:
	Obstacle* obsFactory();
	void changeLight(std::mutex* mtx);

	Direction dir;
	int row;

	Type obsType;
	Color obsColor;
	
	Light* trafficLight;
	Screen sc;

	int time;
	int spawnTime;
	int speed; // 1, 2, 3, 4
	int greenTime;
	int redTime;

	std::vector<Obstacle*> obstacles;
};

#endif