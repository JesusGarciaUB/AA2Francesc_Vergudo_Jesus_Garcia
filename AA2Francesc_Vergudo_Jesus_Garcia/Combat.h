#pragma once

enum CombatScene {START, PLAYER, ENEMY, RESOLUTION, FINISH};

struct Combat {
	//VARIABLES
	CombatScene currentScene;
	char choosenOption;

	//FUNCIONS
	void Init();
	void ShowInterface();
	void StartScene();
	void PlayerScene();
	void EnemyScene();
	void ResolutionScene();
	void FinishScene();
};