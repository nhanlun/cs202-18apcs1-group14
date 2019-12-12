#include "Ambulance.h"

//Ambulance::Ambulance():Obstacle(16,4),figL(4),figR(4)
//{
//	this->x = border;
//	this->y = y;
//	if (dir == Direction::RIGHT) this->x -= (width - 1);
//
//}

Ambulance::Ambulance(int border, int y, Direction dir):Obstacle(16,4),figL(4),figR(4)
{
	this->x = border;
	this->y = y;
	if (dir == Direction::RIGHT) this->x -= (width - 1);
	
	char a = 196;

	std::string tmp = "";
	tmp = tmp + (char)218 + a + a + a + a + a + a + a + a + (char)191 + '_'+ (char)220+char(220)+"_  ";
	figR[0] = tmp;
	figR[1] = "|  ___   |___ \\ ";
	figR[2] = "|_/ _ \\==/ _ \\_]";
	figR[3] = "  \\___/  \\___/  ";

	tmp.clear();
	tmp = tmp + "  _" + (char)220 + char(220) + '_'+ (char)218 + a + a + a + a + a + a + a + a + (char)191;
	figL[0] = tmp;
	figL[1] = " / ___|   ___  |";
	figL[2] = "[_/ _ \\==/ _ \\_|";
	figL[3] = "  \\___/  \\___/  ";

}

void Ambulance::display(Direction dir, const Screen & sc, Color color)
{
	std::string line1, line2, line3, line4;

	if (dir == Direction::LEFT)
	{
		line1 = figL[0];
		line2 = figL[1];
		line3 = figL[2];
		line4 = figL[3];
	}
	else
	{
		line1 = figR[0];
		line2 = figR[1];
		line3 = figR[2];
		line4 = figR[3];
	}

	//Crop if the figure is out of the left border
	int leftOff = sc.offset(x, Direction::LEFT);
	if (leftOff > 0 && leftOff <= width)
	{
		line1 = line1.substr(leftOff, width - leftOff);
		line2 = line2.substr(leftOff, width - leftOff);
		line3 = line3.substr(leftOff, width - leftOff);
		line4 = line4.substr(leftOff, width - leftOff);
	}
	//Crop if the figure is out of the right border
	else {
		int rightOff = sc.offset(x + width, Direction::RIGHT);
		if (rightOff > 0)
		{
			line1 = line1.substr(0, width - rightOff);
			line2 = line2.substr(0, width - rightOff);
			line3 = line3.substr(0, width - rightOff);
			line4 = line4.substr(0, width - rightOff);
		}
	}

	yaosu::color(int(color));
	int row = y, col = max(sc.getLeftBorder(), x);
	yaosu::gotoXY(col, row);
	std::cout << line1;
	yaosu::gotoXY(col, row + 1);
	std::cout << line2;
	yaosu::gotoXY(col, row + 2);
	std::cout << line3;
	yaosu::gotoXY(col, row + 3);
	std::cout << line4;
	yaosu::color(int(Color::DEFAULT));
}

void Ambulance::run(Direction dir,const Screen& sc)
{
	PlaySound(TEXT("Sound/Siren.wav"), NULL, SND_ASYNC);

	if (dir == Direction::LEFT)
	{
		while (!outOfScreen(dir, sc))
		{
			Obstacle::move(dir, sc, Color::RED);
			Sleep(60);
		}
	}
	else
	{
		while (!outOfScreen(dir, sc))
		{
			Obstacle::move(dir, sc, Color::RED);
			Sleep(60);
		}
	}
	yaosu::playThemeSong();
}


