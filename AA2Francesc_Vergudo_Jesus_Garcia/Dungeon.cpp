#include "Dungeon.h"

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
}