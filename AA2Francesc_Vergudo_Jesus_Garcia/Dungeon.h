#pragma once
#include "Player.h"
#include "Chest.h"
#include "Enemy.h"
#include "Logic.h"

struct Dungeon {
	char MAP_RAW[5][5] = {	{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '} };

	Player player;
	vector<Enemy> enemies;
	Chest chests[2];

	void ShowSceneName();
	void ShowHistory();
	void ShowStats();
	void ShowDungeon();
	void ShowPlayerAction();

};