#include "Light.h"
#include "Support.h"

Light::Light() : x(0), y(0), color(Color::GREEN) {}

Light::Light(int _x, int _y, bool isGreen) : x(_x), y(_y), color(Color(isGreen)) {}

bool Light::isGreen() 
{
	return bool(color);
}

void Light::display() 
{
	if (color == Color::GREEN) yaosu::printXY(x, y, char(178), yaosu::GREEN);
	else yaosu::printXY(x, y, char(178), yaosu::RED);
	yaosu::color(yaosu::DEFAULT);
}