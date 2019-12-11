#include "Lane.h"

Lane::Lane(const Screen& sc, Direction _dir, Type _type, int _row, Color _clr, 
	int spawn, Speed _speed, int _green, int _red) : dir(_dir), obsType(_type), 
	row(_row), spawnTime(spawn), speed(_speed), greenTime(_green), 
	redTime(_red), obsColor(_clr), time(0), lightClock(0)
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
	initLane(); //Clear the lane (in case the level is reset)
	randomObstacles(sc);
	while (state == State::RUN || state == State::PAUSE)
	{
		if (state == State::RUN)
		{
			spawnObstacles(sc);
			moveObstacles(sc, ioMtx);
			lightManip(ioMtx);
			if (isImpact(p)) state = State::LOSE;

			//Count the clock
			if (trafficLight->isGreen()) ++time;
			++lightClock;
		}
		Sleep(50);
	}
}

void Lane::initLane()
{
	for (auto const& obstacle : obstacles) delete obstacle;
	obstacles.clear();
	time = lightClock = 0;
	if (trafficLight->isGreen()) trafficLight->changeState();
}

void Lane::randomObstacles(const Screen& sc)
{
	if (dir == Direction::LEFT)
	{
		int x = sc.getRightBorder();
		while (x > sc.getLeftBorder())
		{
			x -= spawnTime / (int)speed;
		}
		x += spawnTime / (int)speed;
		while (x <= sc.getRightBorder())
		{
			Obstacle* tmp = obsFactory(x);
			if (tmp) obstacles.push_back(tmp);
			x += spawnTime / (int)speed;
		}
	}
	else
	{
		int x = sc.getLeftBorder();
		while (x < sc.getRightBorder())
		{
			x += spawnTime / (int)speed;
		}
		x -= spawnTime / (int)speed;
		while (x >= sc.getLeftBorder())
		{
			Obstacle* tmp = obsFactory(x);
			if (tmp) obstacles.push_back(tmp);
			x -= spawnTime / (int)speed;
		}
	}
}

void Lane::spawnObstacles(const Screen& sc)
{
	if (time % spawnTime == 0 && trafficLight->isGreen())
	{
		Obstacle* tmp = obsFactory(sc);
		if (tmp) obstacles.push_back(tmp);
	}
}

void Lane::moveObstacles(const Screen& sc, std::mutex* ioMtx)
{
	if (time % int(speed) == 0 && trafficLight->isGreen())
	{
		ioMtx->lock();
		for (auto& i : obstacles) i->move(dir, sc, obsColor);
		ioMtx->unlock();
		removeObstacles(sc);
	}
}

void Lane::removeObstacles(const Screen& sc)
{
	if (!obstacles.empty() && obstacles[0]->outOfScreen(dir, sc))
	{
		delete obstacles[0];
		obstacles.erase(obstacles.begin());
	}
}

void Lane::lightManip(std::mutex* ioMtx)
{
	if ((trafficLight->isGreen() && lightClock % greenTime == 0) ||
		(!trafficLight->isGreen() && lightClock % redTime == 0))
	{
		changeLight(ioMtx);
		ioMtx->lock();
		trafficLight->display();
		ioMtx->unlock();
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
		if (p->isImpact(i, dir))
			return true;
	return false;
}

void Lane::save(std::ofstream & fo)
{
	/*fo << (int)dir << '\n';
	fo << (int)obsType<<'\n';
	fo << row << '\n';
	fo << (int)obsColor << '\n';
	fo << spawnTime << '\n';
	fo << (int)speed << '\n';*/
	int tmp = (int)dir;
	fo.write((char*)& tmp, 4);
	tmp = (int)obsType;
	fo.write((char*)& tmp, 4);
	fo.write((char*)& row, 4);
	tmp = (int)obsColor;
	fo.write((char*)& tmp, 4);
	fo.write((char*)& spawnTime, 4);
	tmp = (int)speed;
	fo.write((char*)& tmp, 4);
}

void Lane::load(std::ifstream& fin)
{
	int tmp;
	fin.read((char*)& tmp, 4);
	dir = (Direction)tmp;
	fin.read((char*)& tmp, 4);
	obsType = (Type)tmp;
	fin.read((char*)& row, 4);
	fin.read((char*)& tmp, 4);
	obsColor = (Color)tmp;
	fin.read((char*)& spawnTime, 4);
	fin.read((char*)& tmp, 4);
	speed = (Speed)tmp;
}

Obstacle* Lane::obsFactory(const Screen& sc)
{
	int x = 0;
	if (dir == Direction::LEFT) x = sc.getRightBorder();
	else x = sc.getLeftBorder();

	return obsFactory(x);
}

Obstacle* Lane::obsFactory(int x)
{
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