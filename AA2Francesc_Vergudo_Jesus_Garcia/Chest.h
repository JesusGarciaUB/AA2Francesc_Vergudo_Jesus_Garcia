#pragma once
#include "MapPosition.h"
#include "Gear.h"

struct Chest {
	MapPosition pos;
	int gold;
	bool isLooted;
	bool containsPotion;
	Gear gear;

	void Init();
	void ShowChest();
};