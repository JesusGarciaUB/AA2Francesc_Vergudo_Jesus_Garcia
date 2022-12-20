#pragma once
#include "Dungeon.h"
#include "Player.h"
#include "Chest.h"
#include "Enemy.h"
#include "Logic.h"
#include "Combat.h"

enum GameScene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {
	//VARIABLES
	GameScene currentScene;
	Dungeon dungeon;
	Player player;
	vector<Enemy> enemies;
	Chest chests[2];

	//FUNCTIONS
	void Initialize();
	void Spawning();
	int getEnemy(int x, int y);
	/// <summary>
	/// En la dungeon scene se printea la interfaz principal y contiene toda la logica que implique el movimiento
	/// </summary>
	void DungeonScene();
	void CombatScene();
	/// <summary>
	/// En la chest scene se printea la interfaz del cofre y llama a las distintas funciones logicas del cofre 
	/// </summary>
	void ChestScene();
	void GameOverScene();
	/// <summary>
	/// NewRound() se ocupa de reiniciar la posicion de los enemigos cuando acaba una ronda
	/// </summary>
	void NewRound();
	bool AllEnemiesDefeated();
};

/// <summary>/// 
/// Comprueba que el imput del usuario sea W,A,S,D, P
/// </summary>//
bool isValid(string input);