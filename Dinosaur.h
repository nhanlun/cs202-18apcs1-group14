#ifndef DINOSAUR_H_
#define DINOSAUR_H_

#include "Obstacle.h"
#include <vector>
#include <string>

class Dinosaur : public Obstacle
{
public:
	Dinosaur(int x, int y);
	Dinosaur(int border, int y, Direction dir);
	virtual void display(Direction dir, const Screen& sc, Color color = Color::DEFAULT);

private:
	Dinosaur();
	std::vector<std::string> figL;
	std::vector<std::string> figR;
};

#endif