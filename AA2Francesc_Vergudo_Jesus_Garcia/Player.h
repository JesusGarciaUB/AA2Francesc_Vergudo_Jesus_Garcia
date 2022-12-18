#pragma once

struct Player {
	int health;
	int maxHealth;
	int x;
	int y;
	int gold;
	int stamina;
	int agility;
	int potions;
};

void NewPlayer(Player player);