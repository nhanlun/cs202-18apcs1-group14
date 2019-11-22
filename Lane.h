#ifndef LANE_H_
#define LANE_H_

#include "Support.h"
#include "Light.h"
#include "Screen.h"

class Lane
{
public:
	Lane(Direction _dir, Type _type, int _delay, Color _code, int row);
	~Lane();

private:
	Direction dir;
	int timeDelay;
	Type obsType;
	Light* trafficLight;
	Color obsColor;
	Screen sc;
};

#endif