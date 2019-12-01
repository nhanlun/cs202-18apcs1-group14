#ifndef LANE_H_
#define LANE_H_

#include "Bird.h"
#include "Car.h"
#include "Truck.h"
#include "Dinosaur.h"
#include "Player.h"
#include <fstream>

class Lane
{
public:
	Lane(const Screen& sc, Direction _dir, Type _type, int _row, 
		Color _clr = Color::DEFAULT, int spawn = 20, Speed _speed = Speed::SAFE, 
		int _green = 300, int _red = 150);
	~Lane();
	void run(const Screen& sc, std::mutex* ioMtx, State& state, Player* p); // run the clock and update all the object of that lane

	bool isImpact(int x);
	bool isImpact(Player* p) const;
	void save(std::ofstream& fo);

private:
	void randomObstacles(const Screen& sc);	//initialize random obstacles on lane
	void spawnObstacles(const Screen& sc);
	void moveObstacles(const Screen& sc, std::mutex* ioMtx);
	void removeObstacles(const Screen& sc);
	void lightManip(std::mutex* ioMtx);

	Obstacle* obsFactory(const Screen& sc); // spawn at initial position
	Obstacle* obsFactory(int x); //spawn at position x
	void changeLight(std::mutex* mtx);

	Direction dir;
	int row;

	Type obsType;
	Color obsColor;
	
	Light* trafficLight;

	int time;		//lane clock
	int lightClock;	//traffic light clock
	int spawnTime;	//duration to spawn new obstacles
	Speed speed;	//duration the obstacle stop before moving 
	int greenTime;	//duration of green light
	int redTime;	//duration of red light

	std::vector<Obstacle*> obstacles;
};

#endif