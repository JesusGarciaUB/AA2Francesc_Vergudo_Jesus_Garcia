#include "Chest.h"
#include "Logic.h"

void Chest::Init() {
	gold = getRandom(50, 200);
	isLooted = false;
	
	switch (getRandom(10)) {
	case 1:
		gear.name = "Richard's Hatred";
		gear.value = 200;
		gear.HP = 20;
		gear.stamina = 40;
		gear.agility = 1;
		break;
	case 2:
		gear.name = "Swift boots";
		gear.value = 10;
		gear.HP = -10;
		gear.stamina = -5;
		gear.agility = 1;
		break;
	case 3:
		gear.name = "White Powder";
		gear.value = 150;
		gear.HP = -20;
		gear.stamina = 20;
		gear.agility = 1;
		break;
	case 4:
		gear.name = "Radev's Mug";
		gear.value = -300;
		gear.HP = -20;
		gear.stamina = -40;
		gear.agility = -1;
		break;
	case 5:
		gear.name = "Raven feather";
		gear.value = 50;
		gear.HP = -10;
		gear.agility = 2;
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	}
}