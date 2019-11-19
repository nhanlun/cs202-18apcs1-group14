#include "Support.h"
#include <iostream>

namespace yaosu
{
	void fixConsoleWindow()
	{
		HWND consoleWindow = GetConsoleWindow();
		LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
		style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
		SetWindowLong(consoleWindow, GWL_STYLE, style);
	}

	void gotoXY(short x, short y)
	{
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void hideCursor()
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);
	}

	void color(int code)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, code);
	}

	void printXY(short x, short y, char c, int colorCode)
	{
		gotoXY(x, y);
		color(colorCode);
		std::cout << c;
	}
}