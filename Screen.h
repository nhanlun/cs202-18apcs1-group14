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
	int colorMenu();
	int difficultyMenu();

	void levelDisplay(int noLevel);
	void runScreen() const;
	void pauseScreen() const;
	int saveScreen() const;
	int loadScreen() const;
	void saveSuccessfully();

	Light* lightFactory(Direction dir, int row) const; //create traffic light base on lane row and direction

	int getRightBorder() const;
	int getLeftBorder() const;
	void displayMap() const;

	void eraseMap() const;
	void eraseRightPanel(int r1, int r2) const; //erase from row 1 to row 2 in right panel
	void eraseCenter() const;

	void notiLevelUp() const;
	void notiCannotLoad() const;

private:
	void background() const;

	int menuSelect(int option[], int numOptions,int col=98, int row=24) const;
	void displayCursor(int col=98, int row=24) const;
	void moveCursor(int x, int& cur, int numOptions,int col=98,int row=24) const;

	void drawBorder() const;
	void drawCrossyRoad(int x, int y) const; // draw the figure crossy road with sleep x, color y

	const int width = 213;
	const int height = 50;

	const int rightBorder = 120;
	const int leftBorder = 10;

	const int topBorder = 4;
	const int botBorder = 43;
};

#endif