#include <iostream>
#include <conio.h>

#include "Map.h"

int main()
{
	Map game;

	game.runGame("Map.txt");

	while (_kbhit()) { _getch(); }

	printf("\n\nPress any key to quit: ");

	_getch();

	return 0;
}