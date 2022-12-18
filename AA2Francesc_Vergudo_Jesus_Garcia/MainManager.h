#pragma once
#include "Player.h"
#include "Chest.h"
#include "Enemy.h"
#include "Dungeon.h"
#include "Logic.h"

enum GameScene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {
	//VARIABLES
	GameScene currentScene;
	Player player;
	vector<Enemy> enemies;
	Chest chests[2];
	Dungeon dungeon;

	//FUNCTIONS
	void Initialize();
	void Spawning();
};