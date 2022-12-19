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
			system("pause");
			break;
		case COMBAT:
			manager.CombatScene();
			break;
		case CHEST:
			manager.ChestScene();
			system("pause");
			break;
		case GAMEOVER:
			manager.GameOverScene();
			break;
		}
	}

}