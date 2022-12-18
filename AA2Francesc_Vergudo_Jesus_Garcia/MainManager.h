#pragma once
#include "Dungeon.h"
#include "Player.h"
#include "Chest.h"
#include "Enemy.h"
#include "Logic.h"

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
	void DungeonScene();
	void CombatScene();
	void ChestScene();
	void GameOverScene();
};