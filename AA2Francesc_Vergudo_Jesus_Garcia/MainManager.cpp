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

	while (player.agility > 0 && currentScene == DUNGEON)
	{
		char enemyOrChest = ' ';

		dungeon.ShowTopMenu();
		player.ShowStats();
		dungeon.ShowDungeon();
		dungeon.ShowBottomMenu();

		cout << "Enter your action: ";
		string action;
		getline(cin, action);

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

		if (enemyOrChest == 'E')
		{
			currentScene = COMBAT;
		}
		else if (enemyOrChest == 'C') {
			currentScene = CHEST;
		}
	}
	


}

void MainManager::CombatScene() {
	Combat combat;
	combat.Init(player, enemies[getEnemy(player.pos.x, player.pos.y)]);

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
			if (player.health <= 0) currentScene = GAMEOVER;
			else currentScene = DUNGEON;
			fighting = false;
			break;
		}
	}
}

void MainManager::ChestScene() {

	for (int i = 0; i < 1; i++)
	{
		if (player.pos.x == chests[i].pos.x && player.pos.y == chests[i].pos.y) {

			player.maxAgility = player.maxAgility + chests[i].gear.agility;
			player.agility = player.agility + chests[i].gear.agility;


			player.maxStamina = player.maxStamina + chests[i].gear.stamina;
			player.stamina = player.stamina + chests[i].gear.stamina;


			player.maxHealth = player.maxHealth + chests[i].gear.HP;
			player.health = player.health + chests[i].gear.HP;

			player.gold = player.gold + chests[i].gold;

			chests[i].ShowChest();
			if (player.potions < player.maxPotions && chests[i].containsPotion)
			{
				player.potions++;
				cout << "	> The Chest contains a potion!\n";
				cout << "		> You has picked a potion\n";
			}
			chests[i].isLooted = true;
		}
	}

	currentScene = DUNGEON;
}

void MainManager::GameOverScene() {

}

int MainManager::getEnemy(int x, int y) {
	for (int i = 0; i < sizeof(enemies) / sizeof(int); i++) {
		if (enemies[i].pos.x == x && enemies[i].pos.y == y) {
			return i;
		}
	}
}