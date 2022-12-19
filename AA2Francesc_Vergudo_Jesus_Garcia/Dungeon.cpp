#include "Dungeon.h"

void Dungeon::ShowTopMenu() {
	cout << "------DUNGEON------\n\n";
	cout << "E -> Enemy    P -> Player    C -> Chest\n\n";
}

void Dungeon::ShowDungeon() {
	cout << " ___   ___   ___   ___   ___ \n";
	for (int i = 0; i < 5; i++)
	{
		cout << "|   | |   | |   | |   | |   | \n";

		for (int x = 0; x < 5; x++)
		{
			cout << "| " << MAP_RAW[i][x] << " | ";
		}

		cout << "\n|___| |___| |___| |___| |___| \n";
	}
	cout << "___________________________\n\n";
}

void Dungeon::ShowBottomMenu() {
	cout << "W A S D -> Move\n";
	cout << "P -> Potion\n\n";
}

bool Dungeon::IsThereAWall(int x, int y, char key) {
	switch (key)
	{
		case 'W': 
			if (x - 1 < 0) return true;
			break;
		case 'A': 
			if (y - 1 < 0) return true;
			break;
		case 'S': 
			if (x + 1 > 4) return true;
			break;
		case 'D':
			if (y + 1 > 4) return true;
			break;
	default:
		cout << "This shouldn't be possible";
		break;
	}
	return false;
}

char Dungeon::IsThereAnEvent(int x, int y, char key) {
	switch (key)
	{
	case 'W':
		if (MAP_RAW[x - 1][y] == 'E') return 'E';
		if (MAP_RAW[x - 1][y] == 'C') return 'C';
		break;
	case 'A':
		if (MAP_RAW[x][y - 1] == 'E') return 'E';
		if (MAP_RAW[x][y - 1] == 'C') return 'C';
		break;
	case 'S':
		if (MAP_RAW[x + 1][y] == 'E') return 'E';
		if (MAP_RAW[x + 1][y] == 'C') return 'C';
		break;
	case 'D':
		if (MAP_RAW[x][y + 1] == 'E') return 'E';
		if (MAP_RAW[x][y + 1] == 'C') return 'C';
		break;
	default:
		cout << "This shouldn't be possible";
		break;
	}
	return ' ';
}