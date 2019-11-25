#include "Lane.h"

Lane::Lane(const Screen& sc, Direction _dir, Type _type, int _row, Color _clr, 
	int spawn, Speed _speed, int _green, int _red) : dir(_dir), obsType(_type), 
	row(_row), spawnTime(spawn), speed(_speed), greenTime(_green), 
	redTime(_red), obsColor(_clr), time(0)
{
	trafficLight = sc.lightFactory(dir, row);
}

Lane::~Lane()
{
	delete trafficLight;
	for (auto const& obs : obstacles) delete obs;
}

void Lane::run(const Screen& sc, std::mutex* ioMtx, State& state, Player* p)
{
	while (state == State::RUN)
	{
		//Spawn the obstacles
		if (time % spawnTime == 0)
		{
			Obstacle* tmp = obsFactory(sc);
			if (tmp) obstacles.push_back(tmp);
		}

		//Move the obstacles
		if (time % int(speed) == 0 && trafficLight->isGreen())
		{
			ioMtx->lock();
			for (auto& i : obstacles) i->move(dir, sc, obsColor);
			ioMtx->unlock();

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
			changeLight(ioMtx);

			//Turn green
			if (!trafficLight->isGreen())
			{
				Sleep(redTime * 1000);
				changeLight(ioMtx);
			}
		}

		//Check if obstacles are impacted by player
		if (isImpact(p)) state = State::LOSE;

		//Count the clock
		++time;
		Sleep(50);
	}
}

bool Lane::isImpact(int x)
{
	for (auto& i : obstacles)
		if (i->isImpact(x))
			return true;
	return false;
}

bool Lane::isImpact(Player* p) const
{
	for (auto& i : obstacles)
		if (p->isImpact(i))
			return true;
	return false;
}

Obstacle* Lane::obsFactory(const Screen& sc)
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