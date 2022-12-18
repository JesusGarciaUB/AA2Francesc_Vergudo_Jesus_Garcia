#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
}

void MainManager::Spawning() {
	player.pos.x = 4;
	player.pos.y = 2;

	int numOfEnemies = getRandom(5, 7);

	for (int x = 0; x < numOfEnemies; x++) {
		Enemy* enemy = new Enemy();
		enemy->Initialize();



		enemies.push_back(*enemy);
		delete enemy;
	}
}