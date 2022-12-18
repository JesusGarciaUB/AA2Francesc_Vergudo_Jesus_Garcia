#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	player.Initialize();
}

void MainManager::Spawning() {
	player.pos.x = 4;
	player.pos.y = 2;
	dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';

	int numOfEnemies = getRandom(5, 7);
	bool validPosition;

	for (int x = 0; x < numOfEnemies; x++) {
		Enemy* enemy = new Enemy();
		enemy->Initialize();
		validPosition = false;

		while (!validPosition) {
			enemy->pos.RandPosition();

			if (dungeon.MAP_RAW[enemy->pos.x][enemy->pos.y] == ' ') {
				dungeon.MAP_RAW[enemy->pos.x][enemy->pos.y] = 'E';
				validPosition = true;
			}
		}

		enemies.push_back(*enemy);
		delete enemy;
	}

	for (int x = 0; x < 2; x++) {
		Chest* chest = new Chest();
		chest->Init();

		validPosition = false;
		while (!validPosition) {
			chest->pos.RandPosition();

			if (dungeon.MAP_RAW[chest->pos.x][chest->pos.y] == ' ') {
				dungeon.MAP_RAW[chest->pos.x][chest->pos.y] = 'C';
				validPosition = true;
			}
		}

		chests[x] = *chest;
		delete chest;
	}
}

void MainManager::DungeonScene() {
	dungeon.ShowTopMenu();
	player.ShowStats();
	dungeon.ShowDungeon();
	dungeon.ShowBottomMenu();
}

void MainManager::CombatScene() {

}

void MainManager::ChestScene() {
	
}

void MainManager::GameOverScene() {

}