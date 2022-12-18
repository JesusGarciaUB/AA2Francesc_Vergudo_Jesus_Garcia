#include "Enemy.h"
#include "Logic.h"

void Enemy::Initialize() {
	isDead = false;
	maxHealth = getRandom(60, 90);
	health = maxHealth;
	maxStamina = getRandom(60, 90);
	stamina = maxStamina;
}