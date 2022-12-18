#include "Dungeon.h"

void Dungeon::ShowDungeon() {
	cout << " ___  ___  ___  ___  ___ \n";
	for (int i = 0; i < 5; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << "|   |";
			cout << "| " << MAP_RAW[i][x] << " |" << endl;
			cout << "|___|";
		}

		cout << endl;
	}
}