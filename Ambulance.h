#pragma once
#ifndef _Ambulance_h_
#define _Ambulance_h_
#include "Obstacle.h"
#include <vector>
#include <string>
#include <iostream>

class Ambulance : public Obstacle
{
public:
	Ambulance(int border, int y, Direction dir);
	void display(Direction dir, const Screen& sc, Color color = Color::DEFAULT);
	void run(Direction dir, const Screen& sc);
private:
	std::vector<std::string> figL;
	std::vector<std::string> figR;
};

#endif // !_Ambulance_h_#pragma once
