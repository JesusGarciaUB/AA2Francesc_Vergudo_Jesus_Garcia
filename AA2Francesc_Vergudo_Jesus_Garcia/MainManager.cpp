#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	dungeon.player.Initialize();
}

void MainManager::Spawning() {
	dungeon.player.pos.x = 4;
	dungeon.player.pos.y = 2;

	int numOfEnemies = getRandom(5, 7);
	bool validPosition = false;

	for (int x = 0; x < numOfEnemies; x++) {
		Enemy* enemy = new Enemy();
		enemy->Initialize();

		while (!validPosition) {
			enemy->pos.RandPosition();

			if (dungeon.MAP_RAW[enemy->pos.x][enemy->pos.y] == ' ') {

			}
		}

		dungeon.enemies.push_back(*enemy);
		delete enemy;
	}
}