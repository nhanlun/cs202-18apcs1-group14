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
#include "Player.h"

class Lane
{
public:
	Lane(const Screen& sc, Direction _dir, Type _type, int _row, 
		Color _clr = Color::DEFAULT, int spawn = 20, Speed _speed = Speed::SAFE, 
		int _green = 100, int _red = 5);
	~Lane();
	void run(const Screen& sc, std::mutex* ioMtx, State& state, Player* p); // run the clock and update all the object of that lane

	bool isImpact(int x);
	bool isImpact(Player* p) const;

private:
	Obstacle* obsFactory(const Screen& sc);
	void changeLight(std::mutex* mtx);

	Direction dir;
	int row;

	Type obsType;
	Color obsColor;
	
	Light* trafficLight;
	Screen sc;

	int time;
	int spawnTime;
	Speed speed;
	int greenTime;
	int redTime;

	std::vector<Obstacle*> obstacles;
};

#endif