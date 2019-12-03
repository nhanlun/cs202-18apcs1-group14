#include "Support.h"

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

	void setWindow()
	{
		HWND consoleWindow = GetConsoleWindow();
		SetWindowPos(consoleWindow, 0, -5, -5, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD largestSize = GetLargestConsoleWindowSize(h);
		short x = largestSize.X;
		short y = largestSize.Y;

		if (h == INVALID_HANDLE_VALUE)
			throw std::runtime_error("Unable to get stdout handle.");

		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
			throw std::runtime_error("Unable to retrieve screen buffer info.");

		SMALL_RECT& winInfo = bufferInfo.srWindow;
		COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

		if (windowSize.X > x || windowSize.Y > y)
		{
			// window size needs to be adjusted before the buffer size can be reduced.
			SMALL_RECT info =
			{
				0,
				0,
				x < windowSize.X ? x - 1 : windowSize.X - 1,
				y < windowSize.Y ? y - 1 : windowSize.Y - 1
			};

			if (!SetConsoleWindowInfo(h, TRUE, &info))
				throw std::runtime_error("Unable to resize window before resizing buffer.");
		}

		COORD size = { x, y };
		if (!SetConsoleScreenBufferSize(h, size))
			throw std::runtime_error("Unable to resize screen buffer.");


		SMALL_RECT info = { 0, 0, x - 1, y - 1 };
		if (!SetConsoleWindowInfo(h, TRUE, &info))
			throw std::runtime_error("Unable to resize window after resizing buffer.");
	}

	void printCenter(int left, int right, std::string content, int row, Color c)
	{
		color(int(c));
		gotoXY((left + right - content.size()) / 2, row);
		std::cout << content;
		color(int(Color::DEFAULT));
	}

	void playThemeSong()
	{
		PlaySound(TEXT("cs202-18apcs1-group14/Sound/Sunny Day Whistler.wav"), NULL, SND_LOOP | SND_ASYNC);
	}

	void stopThemeSong()
	{
		PlaySound(NULL, NULL, SND_LOOP | SND_ASYNC);
	}

	std::string getStringOf(Type t)
	{
		std::string tmp;
		switch (t)
		{
		case(Type::BIRD):
		{	
			tmp = "BIRD";
			break;
		}
		case(Type::CAR):
		{
			tmp = "CAR";
			break;
		}
		case(Type::DINOSAUR):
		{
			tmp = "DINOSAUR";
			break;
		}
		case(Type::TRUCK):
		{
			tmp = "TRUCK";
			break;
		}
		default:
		{
			tmp = "Mistake";
			break;
		}
		}
		return tmp;
	}
}