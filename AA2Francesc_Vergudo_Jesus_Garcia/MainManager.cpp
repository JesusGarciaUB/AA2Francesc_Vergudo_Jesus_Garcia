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

	while (player.agility > 0)
	{

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
			if (dungeon.IsThereAWall(player.pos.x, player.pos.y, action.at(0))) {
				switch (action.at(0))
				{
					case 'W': 
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = ' ';
						player.pos.x--;
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';
						break;
					case 'A': 
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = ' ';
						player.pos.y--;
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';
						break;
					case 'S': 
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = ' ';
						player.pos.x++;
						dungeon.MAP_RAW[player.pos.x][player.pos.y] = 'P';
						break;
					case 'D':
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

		if (dungeon.MAP_RAW[player.pos.x, player.pos.y] == "E")
		{
			currentScene = COMBAT;
		}
		else if (dungeon.MAP_RAW[player.pos.x, player.pos.y] == "C") {
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
			break;
		}
	}
}

void MainManager::ChestScene() {
	
}

void MainManager::GameOverScene() {

}

int MainManager::getEnemy(int x, int y) {
	for (int i = 0; i < sizeof(enemies) / sizeof(int); x++) {
		if (enemies[i].pos.x == x && enemies[i].pos.y == y) {
			return i;
		}
	}
}