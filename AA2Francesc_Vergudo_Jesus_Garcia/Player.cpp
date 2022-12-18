#include "Player.h"

void Player::Initialize() {
	gold = 0;
	agility = 3;
	potions = 0;


	health = getRandom(90, 110);
	stamina = getRandom(90, 110);

}