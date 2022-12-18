#pragma once

enum GameScene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {
	//VARIABLES
	GameScene currentScene;

	//FUNCTIONS
	void Initialize();
	void Spawning();
};
