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