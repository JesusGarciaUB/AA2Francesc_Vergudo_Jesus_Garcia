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

	/// <summary>
	/// Inicializa el juego
	/// </summary>
	void Initialize();

	/// <summary>
	/// Genera los enemigos, los cofres y el jugador.
	/// </summary>
	void Spawning();

	/// <summary>
	/// Busca un enemigo guardado en memoria a partir de sus coordenadas
	/// </summary>
	/// <param name="x">posicion x</param>
	/// <param name="y">posicion y</param>
	/// <returns>posicion en el vector</returns>
	int getEnemy(int x, int y);

	/// <summary>
	/// En la dungeon scene se printea la interfaz principal y contiene toda la logica que implique el movimiento
	/// </summary>
	void DungeonScene();

	/// <summary>
	/// Escena que se encarga de la logica del combate. Se divide en varias fases
	/// </summary>
	void CombatScene();

	/// <summary>
	/// En la chest scene se printea la interfaz del cofre y llama a las distintas funciones logicas del cofre 
	/// </summary>
	void ChestScene();

	/// <summary>
	/// Escena que se encarga de la logica de final de partida
	/// </summary>
	void GameOverScene();

	/// <summary>
	/// NewRound() se ocupa de reiniciar la posicion de los enemigos cuando acaba una ronda
	/// </summary>
	void NewRound();

	/// <summary>
	/// Comprobamos que todos los enemigos tengan la variable isDead en true
	/// </summary>
	/// <returns>bool</returns>
	bool AllEnemiesDefeated();
};

/// <summary>/// 
/// Comprueba que el imput del usuario sea W,A,S,D, P
/// </summary>//
bool isValid(string input);