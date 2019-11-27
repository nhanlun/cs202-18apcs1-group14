#pragma once
#ifndef _Truck_h_
#define _Truck_h_
#include <string>
#include <vector>
#include "Obstacle.h"

class Truck : public Obstacle
{
public:
	Truck(int x, int y);
	Truck(int border, int y, Direction dir);
	void display(Direction dir, const Screen& sc, Color color = Color::DEFAULT);
private:
	Truck();
	std::vector<std::string> figL;
	std::vector<std::string> figR;
};


#endif // !_Truck_h_
