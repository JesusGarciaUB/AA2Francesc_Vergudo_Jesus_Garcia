#pragma once
#include "MapPosition.h"

struct Enemy {
	MapPosition pos;
	bool isDead;
	int health;
	int maxHealth;
	int stamina;
	int maxStamina;

	/// <summary>
	/// Inicializa un enemigo con unos parametros preestablecidos
	/// </summary>
	void Initialize();
};