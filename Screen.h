#ifndef SCREEN_H_
#define SCREEN_H_

#include "Support.h"

class Screen
{
public:
	Screen();
	bool inScreen(int x, int y) const;
	int offset(int x, Direction dir) const; //num of pixels to remove to fit the screen
	void splashScreen();
private:
	const int width = 213;
	const int height = 50;
};

#endif