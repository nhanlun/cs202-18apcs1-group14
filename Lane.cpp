#include "Lane.h"

Lane::Lane(Direction _dir, Type _type, int _row, int spawn, int _speed, 
	int _green, int _red, Color _clr) : dir(_dir), obsType(_type), row(_row), 
	spawnTime(spawn), speed(_speed), greenTime(_green), redTime(_red), 
	obsColor(_clr)
{
	trafficLight = sc.lightFactory(dir, row);
}

Lane::~Lane()
{
	delete trafficLight;
	for (auto const& obs : obstacles) delete obs;
}

void Lane::run(const Screen& sc, std::mutex* mtx)
{
	while (true)
	{
		//Spawn the obstacles
		if (time % spawnTime == 0)
		{
			Obstacle* tmp = obsFactory();
			if (tmp) obstacles.push_back(tmp);
		}

		//Move the obstacles
		if (time % speed == 0 && trafficLight->isGreen())
		{
			mtx->lock();
			for (auto& i : obstacles) i->move(dir, sc, obsColor);	
			mtx->unlock();

			//Obstacles that run out of map
			if (!obstacles.empty() && obstacles[0]->outOfScreen(dir, sc))
			{
				delete obstacles[0];
				obstacles.erase(obstacles.begin());
			}
		}

		//Traffic light handling
		if (time % greenTime == 0)
		{
			//Turn red
			changeLight(mtx);

			//Turn green
			if (!trafficLight->isGreen())
			{
				Sleep(redTime);
				changeLight(mtx);
			}
		}

		//Count the clock
		++time;
		Sleep(80);
	}
}

Obstacle* Lane::obsFactory()
{
	int x = 0;
	if (dir == Direction::LEFT) x = sc.getRightBorder();
	else x = sc.getLeftBorder();

	switch (obsType)
	{
	case Type::BIRD:
		return new Bird(x, row, dir);
	case Type::CAR:
		return new Car(x, row, dir);
	case Type::DINOSAUR:
		return new Dinosaur(x, row, dir);
	case Type::TRUCK:
		return new Truck(x, row, dir);
	default:
		return nullptr;
	}
}

void Lane::changeLight(std::mutex* mtx)
{
	mtx->lock();
	trafficLight->changeState();
	trafficLight->display();
	mtx->unlock();
}