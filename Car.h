#pragma once
#ifndef _Car_h_
#define _Car_h_
#include <vector>
#include <string>
#include <iostream>
#include "Obstacle.h"
#include "Support.h"

class Car: public Obstacle
{
public:
	Car(int x, int y);
	Car(int border, int y, Direction dir);
	void display(Direction dir, const Screen& sc, Color color = Color::DEFAULT);
private:
	Car();
	std::vector<std::string> figR;
	std::vector<std::string> figL;
};

#endif