#pragma once
#include "Player.h";
#include "Logic.h";

struct Dungeon {
	char MAP_RAW[5][5] = {	{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '} };

	void ShowHistory();
	void ShowStats(Player player);
	void ShowDungeon();
};