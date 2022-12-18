#pragma once

struct Enemy {
	int x;
	int y;
	bool isDead;
	int health;
	int maxHealth;
	int stamina;

	void Initialize();
};
