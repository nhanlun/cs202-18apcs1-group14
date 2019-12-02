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
	int menuScreen(); // 0: new game, 1 : load game, 2 : settings, 3 : exit
	int settingsMenu(); // 0: music on/off, 1: player color

	void levelDisplay(int noLevel);
	void runScreen() const;
	void pauseScreen() const;
	
	Light* lightFactory(Direction dir, int row) const; //create traffic light base on lane row and direction

	int getRightBorder() const;
	int getLeftBorder() const;
	void displayMap() const;

	void eraseMap() const;
	void eraseRightPanel() const;

private:

	void displayCursor();
	void moveCursor(int x, int& cur, int numOptions);

	void drawBorder();
	void drawCrossyRoad(int x, int y); // draw the figure crossy road with sleep x, color y

	const int width = 213;
	const int height = 50;

	const int rightBorder = 120;
	const int leftBorder = 10;

	const int topBorder = 4;
	const int botBorder = 43;
};

#endif