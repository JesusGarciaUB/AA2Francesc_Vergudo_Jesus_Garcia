#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	player.Initialize();
}

void MainManager::Spawning() {
	player.pos.x = 4;
	player.pos.y = 2;

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

		enemies.push_back(*enemy);
		delete enemy;
	}
}

void MainManager::DungeonScene() {

}

void MainManager::CombatScene() {

}

void MainManager::ChestScene() {
	
}

void MainManager::GameOverScene() {

}