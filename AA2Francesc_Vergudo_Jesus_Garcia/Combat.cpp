#include "Combat.h"
#include "Logic.h"
#include <string>

void Combat::Init(Player& x, Enemy& y) {
	player = &x;
	enemy = &y;
	currentScene = START;
}

void Combat::ShowInterface() {
	system("cls");
	cout << "- - - - - - COMBAT - - - - - -" << endl;
	cout << endl << "- - Enemy - -" << endl;
	cout << "[" << GetBar(enemy->maxHealth, enemy->health) << "] ? HP" << endl;
	cout << "[" << GetSta(enemy->maxStamina, enemy->stamina) << "] ? Stamina" << endl;
	cout << endl << "- - - - - - - - - - - -" << endl;
	cout << endl << "- - Player - -" << endl;
	cout << "[" << GetBar(player->maxHealth, player->health) << "] " << player->health << " / " << player->maxHealth << " HP" << endl;
	cout << "[" << GetSta(player->maxStamina, player->stamina) << "] " << player->stamina << " / " << player->maxStamina << " Stamina" << endl;
	cout << endl << "Potions " << player->potions << " / 3" << endl;
	cout << endl << "----------------------------------------------------------------------------" << endl;
	cout << endl << "A -> Attack" << endl << "D -> Defend" << endl << "R -> Rest" << endl << "P -> Potion" << endl;
}

void Combat::FinishScene() {
	if (player->health > 0) {
		cout << "You defeated the enemy!" << endl;
		system("pause");
	}
}

void Combat::StartScene() {
	ShowInterface();
	bool validInput = false;
	string input;

	while (!validInput) {
		cout << endl << "Enter your action: ";
		getline(cin, input);
		validInput = isValid(input);
	}
	choosenOption = input.at(0);
	currentScene = PLAYER;
}

void Combat::ResolutionScene() {
	bool didTurn = false;
	while (!didTurn) {
		if (choosenOption == 'A' && enemyAction == 'A') {
			if (playerStaminaUsed >= enemyStaminaUsed) {
				enemy->health -= playerStaminaUsed;
				cout << endl << "You strike the enemy with more force! The enemy receives  " << playerStaminaUsed << " damage" << endl;
			}
			else {
				player->health -= enemyStaminaUsed;
				cout << endl << "Enemy strikes you with more force! You receive " << enemyStaminaUsed << " damage" << endl;
			}
			didTurn = true;
		}
		if (choosenOption == 'A' && enemyAction == 'D') {
			enemy->health -= playerStaminaUsed * 0.25;
			enemy->stamina += enemy->maxStamina * 0.25;
			if (enemy->stamina > enemy->maxStamina) enemy->stamina = enemy->maxStamina;
			cout << endl << "You strike but enemy defends! The enemy receives " << playerStaminaUsed * 0.25 << " damage" << endl;
			didTurn = true;
		}
		if (choosenOption == 'A' && enemyAction == 'R') {
			enemy->health -= playerStaminaUsed;
			enemy->stamina = enemy->maxStamina;
			if (enemy->stamina > enemy->maxStamina) enemy->stamina = enemy->maxStamina;
			cout << endl << "You strike the resting enemy! The enemy receives " << playerStaminaUsed << " damage" << endl;
			didTurn = true;
		}
		if (choosenOption == 'D' && enemyAction == 'A') {
			player->health -= enemyStaminaUsed * 0.25;
			player->stamina += player->maxStamina * 0.25;
			if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
			cout << endl << "The enemy strikes you while defending! You receive " << enemyStaminaUsed * 0.25 << " damage" << endl;
			didTurn = true;
		}
		if (choosenOption == 'D' && enemyAction == 'D') {
			enemy->stamina += enemy->maxStamina * 0.25;
			player->stamina += player->maxStamina * 0.25;
			if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
			if (enemy->stamina > enemy->maxStamina) enemy->stamina = enemy->maxStamina;
			cout << endl << "You and the enemy defend!" << endl;
			didTurn = true;
		}
		if (choosenOption == 'D' && enemyAction == 'R') {
			player->stamina += player->maxStamina * 0.25;
			enemy->stamina = enemy->maxStamina;
			if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
			if (enemy->stamina > enemy->maxStamina) enemy->stamina = enemy->maxStamina;
			cout << endl << "You defend while the enemy rests!" << endl;
			didTurn = true;
		}
		if (choosenOption == 'R' && enemyAction == 'A') {
			player->stamina = player->maxStamina;
			player->health -= enemyStaminaUsed;
			if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
			cout << endl << "The enemy strikes you while resting! You receive " << enemyStaminaUsed << " damage" << endl;
			didTurn = true;
		}
		if (choosenOption == 'R' && enemyAction == 'D') {
			player->stamina = player->maxStamina;
			enemy->stamina += enemy->maxStamina * 0.25;
			if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
			cout << endl << "You rest while the enemy defends!" << endl;
			didTurn = true;
		}
		if (choosenOption == 'R' && enemyAction == 'R') {
			player->stamina = player->maxStamina;
			enemy->stamina = enemy->maxStamina;
			if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
			cout << endl << "You both rest!" << endl;
			didTurn = true;
		}
		if (choosenOption == 'P' && enemyAction == 'A') {
			if (potionsAux) {
				cout << endl << "You heal for " << player->maxHealth * 40 / 100<< endl;
			}
			player->health -= enemyStaminaUsed;
			cout << endl << "The enemy strikes you! You receive " << enemyStaminaUsed << " damage" << endl;
			didTurn = true;
		}
		if (choosenOption == 'P' && enemyAction == 'D') {
			if (potionsAux) {
				cout << endl << "You heal for " << player->maxHealth * 40 / 100 << endl;
			}
			enemy->stamina += enemy->maxStamina * 0.25;
			if (enemy->stamina > enemy->maxStamina) enemy->stamina = enemy->maxStamina;
			didTurn = true;
		}
		if (choosenOption == 'P' && enemyAction == 'R') {
			if (potionsAux) {
				cout << endl << "You heal for " << player->maxHealth * 40 / 100 << endl;
			}
			enemy->stamina = enemy->maxStamina;
			if (enemy->stamina > enemy->maxStamina) enemy->stamina = enemy->maxStamina;
			didTurn = true;
		}
		if (enemy->health > 0) system("pause");
		if (player->health <= 0 || enemy->health <= 0) currentScene = FINISH;
		else currentScene = START;
	}
}

void Combat::EnemyScene() {
	if (enemy->health < enemy->maxHealth * 0.3 && enemy->stamina < enemy->maxStamina * 0.3) enemyAction = 'D';
	else if (enemy->stamina < enemy->maxStamina * 0.2) enemyAction = 'R';
	else EnemyAttacks();
	currentScene = RESOLUTION;
}

void Combat::EnemyAttacks() {
	enemyAction = 'A';
	enemyStaminaUsed = getRandom(enemy->maxStamina * 0.2, enemy->stamina);
	enemy->stamina -= enemyStaminaUsed;
	
}

void Combat::PlayerScene() {
	if (choosenOption == 'A') playerAttacks();
	int currentPotion = player->potions;
	if (choosenOption == 'P') {
		player->UsePotion();
		potionsAux = currentPotion == player->potions ? false : true;
	}
	currentScene = ENEMY;
}

void Combat::playerAttacks() {
	bool isValidStamina = false;
	string aux = "";
	while (!isValidStamina) {
		cout << endl << "Enter your attack value (Max " << player->stamina << "): "; 
		getline(cin, aux);
		playerStaminaUsed = stoi(aux);
		isValidStamina = validStamina(playerStaminaUsed);
		if (!isValidStamina) cout << "Invalid attack value" << endl;
	}
	player->stamina -= playerStaminaUsed;
}

string Combat::GetBar(int max, int current) {
	string _return;
	int to_loop = ((current * 100) / max)/10;
	if (player->health > 0 && to_loop < 1) to_loop = 1;
	for (int x = 0; x < to_loop; x++) {
		_return += "=";
	}
	for (int x = 0; x < 10 - to_loop; x++) {
		_return += " ";
	}
	return _return;
}

string Combat::GetSta(int max, int current) {
	string _return;
	int to_loop = ((current * 100) / max)/10;
	for (int x = 0; x < to_loop; x++) {
		_return += ">";
	}
	for (int x = 0; x < 10 - to_loop; x++) {
		_return += " ";
	}
	return _return;
}

bool Combat::isValid(string option) {
	if (option == "A" && player->stamina > 0|| option == "D" || option == "R" || option == "P") return true;
	if (option == "A" && player->stamina <= 0) cout << endl << "You don't have stamina to attack!";
	else cout << endl << "Invalid input";
	return false;
}

bool Combat::validStamina(int input) {
	if (input > player->stamina || input <= 0) return false;
	return true;
}