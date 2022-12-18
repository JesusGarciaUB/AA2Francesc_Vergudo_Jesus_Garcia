#include "Combat.h"

void Combat::Init(Player& x, Enemy& y) {
	currentScene = START;
	player = &x;
	enemy = &y;
}

void Combat::ShowInterface() {
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
	cout << endl << "Enter your action: ";
}

void Combat::StartScene() {
	
}

string Combat::GetBar(int max, int current) {
	string _return;
	int to_loop = (current * 100) / max;
	for (int x = 0; x < to_loop; x++) {
		_return += "=";
	}
}

string Combat::GetSta(int max, int current) {
	string _return;
	int to_loop = (current * 100) / max;
	for (int x = 0; x < to_loop; x++) {
		_return += ">";
	}
}