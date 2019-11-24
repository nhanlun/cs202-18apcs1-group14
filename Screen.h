#ifndef SCREEN_H_
#define SCREEN_H_

#include "Support.h"
#include "Light.h"

class Screen
{
public:
	Screen();
	bool inScreen(int x, int y) const;
	int offset(int x, Direction dir) const; //num of pixels to remove to fit the screen
	void splashScreen();
	Light* lightFactory(Direction dir, int row); //create traffic light base on lane row and direction

	int getRightBorder() const;
	int getLeftBorder() const;

private:
	const int width = 213;
	const int height = 50;

	const int rightBorder = 50;
	const int leftBorder = 10;
};

#endif