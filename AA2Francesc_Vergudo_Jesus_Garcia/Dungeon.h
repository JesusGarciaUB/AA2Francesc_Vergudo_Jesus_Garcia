#pragma once
#include "Logic.h"

struct Dungeon {
	char MAP_RAW[5][5] = {	{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '} };

	void ShowTopMenu();
	void ShowDungeon();
	void ShowBottomMenu();
	bool IsThereAWall(int x, int y, char key);
	char IsThereAnEvent(int x, int y, char key);
};