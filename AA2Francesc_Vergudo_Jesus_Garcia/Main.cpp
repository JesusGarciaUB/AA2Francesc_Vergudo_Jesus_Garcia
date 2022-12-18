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
			break;
		case COMBAT:
			break;
		case CHEST:
			break;
		case GAMEOVER:
			break;
		}
	}
}