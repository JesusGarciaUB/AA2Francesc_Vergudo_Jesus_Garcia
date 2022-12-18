#include <iostream>
#include "MainManager.h"

using namespace std;
int cosa = 1;
void main() {
	MainManager manager;
	manager.Initialize();

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