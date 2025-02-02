#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	player.Initialize();
}

void MainManager::Spawning() {
	player.pos.x = 4;
	player.pos.y = 2;
	dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';

	int numOfEnemies = getRandom(5, 7);
	bool validPosition;

	for (int x = 0; x < numOfEnemies; x++) {
		Enemy* enemy = new Enemy();
		enemy->Initialize();
		validPosition = false;
		
		while (!validPosition) {
			enemy->pos.RandPosition();
			
			if (dungeon.MAP_RAW[enemy->pos.x][enemy->pos.y] == ' ') {
				dungeon.MAP_RAW[enemy->pos.x][enemy->pos.y] = 'E';
				validPosition = true;
			}
		}

		enemies.push_back(*enemy);
		delete enemy;
	}

	for (int x = 0; x < 2; x++) {
		Chest* chest = new Chest();
		chest->Init();

		validPosition = false;
		while (!validPosition) {
			chest->pos.RandPosition();

			if (dungeon.MAP_RAW[chest->pos.x][chest->pos.y] == ' ') {
				dungeon.MAP_RAW[chest->pos.x][chest->pos.y] = 'C';
				validPosition = true;
			}
		}

		chests[x] = *chest;
		delete chest;
	}
}

void MainManager::DungeonScene() {

	if (AllEnemiesDefeated() && chests[0].isLooted && chests[1].isLooted) currentScene = GAMEOVER;
	if (player.health <= 0) currentScene = GAMEOVER;

	if (player.agility == 0 && currentScene == DUNGEON)
	{
		NewRound();
	}

	while (player.agility > 0 && currentScene == DUNGEON)
	{
		char enemyOrChest = ' ';

		dungeon.ShowTopMenu();
		player.ShowStats();
		dungeon.ShowDungeon();
		dungeon.ShowBottomMenu();
		string action = "";
		bool validInput = false;
		while (!validInput) {
			cout << endl << "Enter your action: ";
			getline(cin, action);
			validInput = isValid(action);
		}
		
		switch (action.at(0))
		{
		case 'W': case 'A': case 'S': case 'D':
			if (!dungeon.IsThereAWall(player.pos.x, player.pos.y, action.at(0))) {
				switch (action.at(0))
				{
					case 'W': 
						enemyOrChest = dungeon.IsThereAnEvent(player.pos.x, player.pos.y, action.at(0));
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = ' ';
						player.pos.x--;
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';
						break;
					case 'A': 
						enemyOrChest = dungeon.IsThereAnEvent(player.pos.x, player.pos.y, action.at(0));
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = ' ';
						player.pos.y--;
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';
						break;
					case 'S': 
						enemyOrChest = dungeon.IsThereAnEvent(player.pos.x, player.pos.y, action.at(0));
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = ' ';
						player.pos.x++;
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';
						break;
					case 'D':
						enemyOrChest = dungeon.IsThereAnEvent(player.pos.x, player.pos.y, action.at(0));
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = ' ';
						player.pos.y++;
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';
						break;
				default:
					cout << "This shouldn't be possible";
					break;
				}
				player.agility--;
			}
			else
			{
				cout << "There is a wall! ";
			}
			
			break;
		case 'P':
			player.UsePotion();
			break;
		default:
			cout << "Your action was invalid! ";
			break;
		}
		system("cls");
		if (enemyOrChest == 'E')
		{
			currentScene = COMBAT;
		}
		else if (enemyOrChest == 'C') {
			currentScene = CHEST;
		}
		if (AllEnemiesDefeated() && chests[0].isLooted && chests[1].isLooted) currentScene = GAMEOVER;
		if (player.health <= 0) currentScene = GAMEOVER;
	}
}

void MainManager::CombatScene() {
	Combat combat;
	combat.Init(player, enemies.at(getEnemy(player.pos.x, player.pos.y)));

	bool fighting = true;
	while (fighting) {
		switch (combat.currentScene) {
		case START:
			combat.StartScene();
			break;
		case PLAYER:
			combat.PlayerScene();
			break;
		case ENEMY:
			combat.EnemyScene();
			break;
		case RESOLUTION:
			combat.ResolutionScene();
			break;
		case FINISH:
			combat.FinishScene();
			fighting = false;
			break;
		}
	}
	if (AllEnemiesDefeated() && chests[0].isLooted && chests[1].isLooted) currentScene = GAMEOVER;
	if (player.health <= 0) currentScene = GAMEOVER;
	else currentScene = DUNGEON;

	enemies.at(getEnemy(player.pos.x, player.pos.y)).isDead = true;
	system("cls");
}

void MainManager::ChestScene() {

	for (Chest& c : chests) {
		if (player.pos.x == c.pos.x && player.pos.y == c.pos.y) {

			player.maxAgility = player.maxAgility + c.gear.agility;
			if (player.agility > player.maxAgility) player.agility = player.maxAgility;


			player.maxStamina = player.maxStamina + c.gear.stamina;
			if (player.stamina > player.maxStamina) player.stamina = player.maxStamina;


			player.maxHealth = player.maxHealth + c.gear.HP;
			if (player.health > player.maxHealth) player.health = player.maxHealth;

			player.gold = player.gold + c.gold + c.gear.value;

			c.ShowChest();
			if (player.potions < player.maxPotions && c.containsPotion)
			{
				player.potions++;
				cout << "	> The Chest contains a potion!\n";
				cout << "		> You has picked a potion\n";
			}
			c.isLooted = true;
		}
	}

	system("pause");
	if (AllEnemiesDefeated() && chests[0].isLooted && chests[1].isLooted) currentScene = GAMEOVER;
	currentScene = DUNGEON;
}

//PUNTUACIO
void MainManager::GameOverScene() {
	system("cls");
	if (player.health <= 0) {
		cout << "> You LOST! Radev's laughing right now. Your final score is: " << player.gold << endl;
		cout << endl << "Thanks for playing :)" << endl;
		system("pause");
	}
	else {
		cout << "You WON! Radev's minions are no more. Your final score is: " << player.gold << endl;
		cout << endl << "Thanks for playing :)" << endl;
		system("pause");
	}
}

int MainManager::getEnemy(int x, int y) {
	int cont = 0;

	for (Enemy& e : enemies) {
		if (e.pos.x == x && e.pos.y == y) {
			return cont;
		}
		cont++;
	}
}

void MainManager::NewRound() {

	for (Enemy& e : enemies) {
		dungeon.MAP_RAW[e.pos.x][e.pos.y] = ' ';
	}

	bool validPosition;
	for (Enemy& e : enemies) {
		validPosition = false;

		while (!validPosition) {
			e.pos.RandPosition();

			if (dungeon.MAP_RAW[e.pos.x][e.pos.y] == ' ') {
				if (!e.isDead) dungeon.MAP_RAW[e.pos.x][e.pos.y] = 'E';
				validPosition = true;
			}
		}
	}

	player.agility = player.maxAgility;

	dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';

}

bool isValid(string input) {
	if (input.at(0) == 'W' || input.at(0) == 'A' || input.at(0) == 'S' || input.at(0) == 'D' || input.at(0) == 'P') return true;
	return false;
}

bool MainManager::AllEnemiesDefeated() {
	for (Enemy& e : enemies) {
		if (!e.isDead) return false;
	}
	return true;
}