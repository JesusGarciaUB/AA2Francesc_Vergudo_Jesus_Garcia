#include "Player.h"

void Player::Initialize() {
	gold = 0;

	maxAgility = 3;
	agility = 3;

	maxPotions = 3;
	potions = 3;

	maxHealth = getRandom(90, 110);
	health = maxHealth;

	maxStamina = getRandom(90, 110);
	stamina = maxStamina;
}

void Player::ShowStats() {
	cout << "Health: " << health << " / " << maxHealth << "\n";
	cout << "Potions: " << potions << " / " << maxPotions << "\n";
	cout << "Moves: " << agility << " / " << maxAgility << "\n\n";
}

void Player::UsePotion() {

	if (potions > 0)
	{
		health += maxHealth % 40;

		if (health > maxHealth)
		{
			health = maxHealth;
		}

		potions--;
	}
	else
	{
		cout << "You are out of POTIONS \n";
	}
	
}