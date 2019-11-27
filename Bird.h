#ifndef BIRD_H_
#define BIRD_H_

#include "Obstacle.h"
#include <vector>
#include <string>

class Bird : public Obstacle
{
public:
	Bird(int x, int y);
	Bird(int border, int y, Direction dir);
	virtual void display(Direction dir, const Screen& sc, Color color = Color::DEFAULT);

private:
	Bird();
	std::vector<std::string> figL;
	std::vector<std::string> figR;
};

#endif