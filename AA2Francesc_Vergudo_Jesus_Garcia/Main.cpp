#include "MainManager.h"

void main() {
	srand(time(NULL));
	MainManager manager;
	manager.Initialize();
	manager.Spawning();
	
	bool playing = true;
	
	while (playing) {
		switch (manager.currentScene) {
		case DUNGEON:
			manager.DungeonScene();
			break;
		case COMBAT:
			manager.CombatScene();
			break;
		case CHEST:
			manager.ChestScene();
			break;
		case GAMEOVER:
			manager.GameOverScene();
			playing = false;
			break;
		}
	}

}