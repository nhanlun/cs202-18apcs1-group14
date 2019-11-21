#ifndef DINOSAUR_H_
#define DINOSAUR_H_

#include "Obstacle.h"
#include <vector>
#include <string>

class Dinosaur : public Obstacle
{
public:
	Dinosaur(int x, int y);
	virtual void display(Direction dir, const Screen& sc);

private:
	std::vector<std::string> figL;
	std::vector<std::string> figR;
};

#endif