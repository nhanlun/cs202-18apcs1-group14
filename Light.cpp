#include "Light.h"
#include "Support.h"

Light::Light() : x(0), y(0), color(LightColor::GREEN) {}

Light::Light(int _x, int _y, bool isGreen) : x(_x), y(_y), color(LightColor(isGreen)) {}

bool Light::isGreen() 
{
	return bool(color);
}

void Light::display() 
{
	if (color == LightColor::GREEN) yaosu::printXY(x, y, char(178), int(Color::GREEN));
	else yaosu::printXY(x, y, char(178), int(Color::RED));
	yaosu::color(int(Color::DEFAULT));
}