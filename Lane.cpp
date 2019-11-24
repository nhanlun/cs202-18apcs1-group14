#include "Lane.h"

Lane::Lane(Direction _dir, Type _type, int _delay, Color _code, int row, int speed, int _lightDelay) : 
	dir(_dir), obsType(_type), timeDelay(_delay), obsColor(_code), time(0), speed(speed), row(row), 
	lightDelay(_lightDelay)
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
	int x = dir == Direction::LEFT ? sc.getRightBorder() : sc.getLeftBorder();
	while (true)
	{
		if (time % timeDelay == 0)
		{
			Obstacle* tmp = nullptr;
			switch (obsType)
			{
			case Type::BIRD:
				tmp = new Bird(x, row, dir);
				break;
			case Type::CAR:
				tmp = new Car(x, row);
				break;
			case Type::DINOSAUR:
				tmp = new Dinosaur(x, row);
				break;
			case Type::TRUCK:
				tmp = new Truck(x, row);
				break;
			}
			
			obstacles.push_back(tmp);
		}
		if (time % speed == 0 && trafficLight->isGreen())
		{
			mtx->lock();
			for (auto& i : obstacles)
			{
				i->move(dir, sc, obsColor);
			}
			mtx->unlock();
		}
		if (time % lightDelay == 0)
		{
			mtx->lock();
			trafficLight->changeState();
			trafficLight->display();
			mtx->unlock();
		}
		Sleep(80);
		++time;
	}
}
