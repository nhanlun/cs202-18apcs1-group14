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
	Car();
	Car(int x, int y);
	void display(); 
private:
	std::vector<std::string> figureR;
	std::vector<std::string> figureL;
};

#endif