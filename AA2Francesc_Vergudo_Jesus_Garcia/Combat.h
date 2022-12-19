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

	//FUNCIONS
	void Init(Player& player, Enemy& enemy);
	void ShowInterface();
	void StartScene();
	void PlayerScene();
	void EnemyScene();
	void ResolutionScene();
	void FinishScene();
	string GetBar(int max, int current);
	string GetSta(int max, int current);
	void playerAttacks();
	void EnemyAttacks();
	bool validStamina(int input);
};

bool isValid(string option);