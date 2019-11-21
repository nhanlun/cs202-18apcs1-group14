#ifndef SCREEN_H_
#define SCREEN_H_

#include "Support.h"

class Screen
{
public:
	bool inScreen(int x, int y) const;
	int offset(int x, Direction dir) const; //num of pixels to remove to fit the screen

private:
	const int width = 213;
	const int height = 49;
};

#endif