#pragma once
#include "Logic.h"

struct Dungeon {
	char MAP_RAW[5][5] = {	{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' '} };
	/// <summary>
	/// Muestra la parte superior del menu de DUNGEON
	/// </summary>
	void ShowTopMenu();

	/// <summary>
	/// Muestra el mapa de la dungeon
	/// </summary>
	void ShowDungeon();

	/// <summary>
	/// Muestra la parte inferior del menu de DUNGEON
	/// </summary>
	void ShowBottomMenu();

	/// <summary>
	/// Comprueba si hay o no un muro cuando el jugador se mueve
	/// </summary>
	bool IsThereAWall(int x, int y, char key);

	/// <summary>
	/// Comprueba si hay un enemigo o un cofre cuando el jugador se mueve
	/// </summary>
	char IsThereAnEvent(int x, int y, char key);
};