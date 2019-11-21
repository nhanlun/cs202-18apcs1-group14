#pragma once
#ifndef _Truck_h_
#define _Truck_h_
#include <string>
#include <vector>
#include "Obstacle.h"

class Truck : public Obstacle
{
public:
	Truck();
	Truck(int x, int y);
	void display(Direction dir, const Screen& sc);
private:
	std::vector<std::string> figL;
	std::vector<std::string> figR;
};


#endif // !_Truck_h_
