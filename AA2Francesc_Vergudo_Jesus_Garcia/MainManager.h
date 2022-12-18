#pragma once
#include "Dungeon.h"
#include "Logic.h"

enum GameScene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {
	//VARIABLES
	GameScene currentScene;
	Dungeon dungeon;

	//FUNCTIONS
	void Initialize();
	void Spawning();
};