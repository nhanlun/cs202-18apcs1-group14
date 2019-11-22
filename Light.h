#ifndef LIGHT_H_
#define LIGHT_H_

class Light 
{
public:
	Light();
	Light(int x, int y, bool isGreen);
	bool isGreen();
	void display();

private:
	enum class LightColor {RED, GREEN};

	int x, y;
	LightColor color;
};

#endif