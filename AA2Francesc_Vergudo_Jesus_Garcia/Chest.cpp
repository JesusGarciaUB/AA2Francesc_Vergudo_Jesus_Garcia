#include "Chest.h"
#include "Logic.h"

void Chest::Init() {
	gold = getRandom(50, 200);
	isLooted = false;
	
	switch (getRandom(1, 10)) {
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
		gear.name = "Red Mushroom";
		gear.value = 170;
		gear.HP = 30;
		break;
	case 7:
		gear.name = "Ugly Facemask";
		gear.value = 10;
		gear.HP = 5;
		break;
	case 8:
		gear.name = "Broken Shield";
		gear.value = 25;
		gear.HP = 10;
		break;
	case 9:
		gear.name = "Green Mushroom";
		gear.value = -50;
		gear.stamina = -10;
		break;
	case 10:
		gear.name = "Naughty book";
		gear.value = 69;
		gear.stamina = 7;
		break;
	}

	containsPotion = getRandom(1, 100) > 75 ? true : false;
}

void Chest::ShowChest() {
	string stats = " ";
	if (gear.agility > 0) stats += "+" + to_string(gear.agility) + " agility ";
	if (gear.agility < 0) stats += to_string(gear.agility) + " agility ";

	if (gear.HP > 0) stats += "+" + to_string(gear.HP) + " HP ";
	if (gear.HP < 0) stats += to_string(gear.HP) + " HP ";

	if (gear.stamina > 0) stats += "+" + to_string(gear.stamina) + " stamina ";
	if (gear.stamina < 0) stats += to_string(gear.stamina) + " stamina ";

	cout << "------ CHEST ------\n\n";
	cout << " > You open the chest and it contains the following: \n\n";
	cout << "	> " << gold << " gold!\n";
	cout << "	> The Chest contains Gear!\n";
	cout << "		> " << gear.name << " " << stats << "\n";

	/*if (containsPotion)
	{
		cout << "		> The Chest contains a potion!";
		cout << "				> " << gear.name << " " << stats;
	}*/
}