#pragma once
#include "Dungeon.h"
#include "Player.h"
#include "Chest.h"
#include "Enemy.h"
#include "Logic.h"
#include "Combat.h"

enum GameScene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {
	//VARIABLES
	GameScene currentScene;
	Dungeon dungeon;
	Player player;
	vector<Enemy> enemies;
	Chest chests[2];

	//FUNCTIONS
	void Initialize();
	void Spawning();
	int getEnemy(int x, int y);
	void DungeonScene();
	void CombatScene();
	void ChestScene();
	void GameOverScene();
	void NewRound();
};

bool isValid(string input);