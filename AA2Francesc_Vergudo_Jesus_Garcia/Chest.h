#pragma once
#include "MapPosition.h"
#include "Gear.h"

struct Chest {
	MapPosition pos;
	int gold;
	bool isLooted;
	bool containsPotion;
	Gear gear;


	/// <summary>
	/// Inicializa el cofre
	/// </summary>
	void Init();

	/// <summary>
	/// Enseña la interfaz del cofre
	/// </summary>
	void ShowChest();
};