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

	/// <summary>
	///  Initialize() inicializa un jugador
	/// 
	///	 UsePotion() comprueba si el juegador tiene pociones y si tiene usa una.
	/// 
	/// ShowStats() muestra las estadisticas base del jugador (Vida, pociones y movimientos). Se usa para printearlo en la interfaz de dungeon
	/// </summary>

	void Initialize();
	void UsePotion();
	void ShowStats();
};