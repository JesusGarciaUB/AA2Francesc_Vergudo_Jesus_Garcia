#include "MainManager.h"

using namespace std;

void main() {
	srand(time(NULL));
	MainManager manager;
	manager.Initialize();

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