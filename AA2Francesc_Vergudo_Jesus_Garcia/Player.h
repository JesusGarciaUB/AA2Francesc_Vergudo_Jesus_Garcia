#pragma once
#include "Logic.h"
#include "MapPosition.h"

struct Player {
	MapPosition pos;
	int gold;

	int health;
	int maxHealth;

	int stamina;
	int maxStamina;

	int agility;
	int maxAgility;

	int potions;
	int maxPotions;

	void Initialize();
	void UsePotion();
	void ShowStats();
	void Move();
};