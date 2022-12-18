#pragma once
#include "Logic.h"

struct Dungeon {
	char MAP_RAW[5][5] = {	{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '} };

	void ShowDungeon();
};