#include "Level.h"

int main() 
{
	srand(time(NULL));
	Screen sc;
	Level level(10, sc);
	level.run(sc);
	return 0;
}