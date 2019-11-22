#include "Lane.h"

Lane::Lane(Direction _dir, Type _type, int _delay, Color _code, int row) : 
	dir(_dir), obsType(_type), timeDelay(_delay), obsColor(_code)
{
	trafficLight = sc.lightFactory(dir, row);
}

Lane::~Lane()
{
	delete trafficLight;
}