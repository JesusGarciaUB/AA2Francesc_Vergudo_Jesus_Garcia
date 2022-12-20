#pragma once
#include "Player.h"
#include "Enemy.h"

enum CombatScene {START, PLAYER, ENEMY, RESOLUTION, FINISH};

struct Combat {
	//VARIABLES
	CombatScene currentScene;
	char choosenOption;
	Player* player;
	Enemy* enemy;
	int playerStaminaUsed;
	char enemyAction;
	int enemyStaminaUsed;
	bool potionsAux;

	//FUNCIONES

	/// <summary>
	/// Inicializa un combate entre player y un enemigo
	/// </summary>
	/// <param name="player">Player</param>
	/// <param name="enemy">Enemy (use getEnemy())</param>
	void Init(Player& player, Enemy& enemy);
	
	/// <summary>
	/// Visibiliza el estado del combate y las estadisticas
	/// </summary>
	void ShowInterface();

	/// <summary>
	/// Ejecuta un ShowInterface() y pregunta al usuario por un input valido
	/// </summary>
	void StartScene();

	/// <summary>
	/// Logica del input del player
	/// </summary>
	void PlayerScene();

	/// <summary>
	/// IA del enemigo
	/// </summary>
	void EnemyScene();

	/// <summary>
	/// Simula un turno de combate en base a las acciones del jugador y del enemigo. Debe usarse siempre despues de PlayerScene() Y EnemyScene()
	/// </summary>
	void ResolutionScene();

	/// <summary>
	/// Comprueba si la batalla ha acabado y realiza los ajustes de escena necesarios
	/// </summary>
	void FinishScene();

	/// <summary>
	/// Escala una barra de vida grafica a los porcentajes de vida actuales
	/// </summary>
	/// <param name="max">Maximo de vida</param>
	/// <param name="current">Vida actual</param>
	/// <returns>String con la barra de vida</returns>
	string GetBar(int max, int current);

	/// <summary>
	/// Escala una barra de stamina grafica a los porcentajes de stamina actuales
	/// </summary>
	/// <param name="max">Maxima stamina</param>
	/// <param name="current">Stamina actual</param>
	/// <returns>String con barra de stamina</returns>
	string GetSta(int max, int current);

	/// <summary>
	/// Si el jugador ataca se llama a esta funcion
	/// </summary>
	void playerAttacks();

	/// <summary>
	/// Si el enemigo ataca se llama a esta funcion
	/// </summary>
	void EnemyAttacks();

	/// <summary>
	/// Comprueva que introduzcas un valor de stamina valido
	/// </summary>
	/// <param name="input">Input del jugador</param>
	/// <returns>bool</returns>
	bool validStamina(int input);

	/// <summary>
	/// Comprueva que el input del jugador sea valido y que si pretende atacar disponga de mas de 0 de stamina
	/// </summary>
	/// <param name="option">Input del jugador</param>
	/// <returns>bool</returns>
	bool isValid(string option);
};