#pragma once
#ifndef _Obstacle_h_
#define _Obstacle_h_

class Obstacle
{
public:
	virtual void display() = 0;
	virtual void move(int dir) = 0;
private:
	int x, y;
};

#endif