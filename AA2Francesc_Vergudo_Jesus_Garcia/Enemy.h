#pragma once
#include "MapPosition.h"

struct Enemy {
	MapPosition pos;
	bool isDead;
	int health;
	int maxHealth;
	int stamina;
	int maxStamina;

	void Initialize();
};