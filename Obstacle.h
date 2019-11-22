#ifndef _Obstacle_h_
#define _Obstacle_h_

#include "Support.h"
#include "Screen.h"

class Obstacle
{
public:
	Obstacle(int w, int h);
	Obstacle(int _x, int _y, int w, int h);
	virtual ~Obstacle();

	void move(Direction dir, const Screen& sc, Color color = Color::DEFAULT);
	virtual void display(Direction dir, const Screen& sc, Color color = Color::DEFAULT) = 0;
	bool isImpact(int playerX, int playerY);

protected:
	int x, y; //top-left corner
	int width, height; //size of figures

private:
	void hide(Direction dir);
};

#endif