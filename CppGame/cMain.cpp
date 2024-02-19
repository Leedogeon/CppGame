#include <stdio.h>
#include <Windows.h>
#define BulletCount 10
#define EnemyCount 10
#pragma region Enum
enum COLOR
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,

};

#pragma endregion

#pragma region Struct

struct Player
{
	bool act;
	int x;
	int y;
	int aniIndex;
	COLOR color;
	const char* shape[10][3];
};

struct Enemy
{
	bool act;
	int x;
	int y;
	COLOR color;
	const char* shape[3];
};

struct Bullet
{
	bool act;
	int x;
	int y;
	COLOR color;
	const char* shape;
};
#pragma endregion


#pragma region Game
Player* player = nullptr;
Enemy* enemy[EnemyCount] = {};
Bullet* bullets[BulletCount] = {};
void StageInitialize();
void StageProgress();
void StageRender();
void StageRelease();
#pragma endregion

#pragma region WIN_API
void MovePos(int x, int y);
void Paint(int color);
void HideCursor();

#pragma endregion

int main()
{
	HideCursor();
	StageInitialize();


	while (true)
	{
		system("cls");
		StageProgress();
		StageRender();
		Sleep(20);

	}

	StageRelease();

	return 0;
}

#pragma region Stage
void StageInitialize()
{

	player = (Player*)malloc(sizeof(Player));
	player->act = true;
	player->color = WHITE;
	player->x = 10;
	player->y = 10;
	player->color = WHITE;
	player->aniIndex = 0;
	player->shape[0][0] = "   -----|-----";
	player->shape[0][1] = "*>=====[_]L)";
	player->shape[0][2] = "      -'-`-";

	player->shape[1][0] = "    ----|---- ";
	player->shape[1][1] = "*>=====[_]L)";
	player->shape[1][2] = "      -'-`-";

	player->shape[2][0] = "     ---|---  ";
	player->shape[2][1] = "*>=====[_]L)";
	player->shape[2][2] = "      -'-`-";

	player->shape[3][0] = "      --|--   ";
	player->shape[3][1] = "*>=====[_]L)";
	player->shape[3][2] = "      -'-`-";

	player->shape[4][0] = "       -|-    ";
	player->shape[4][1] = "*>=====[_]L)";
	player->shape[4][2] = "      -'-`-";

	player->shape[5][0] = "        +     ";
	player->shape[5][1] = "*>=====[_]L)";
	player->shape[5][2] = "      -'-`-";

	player->shape[6][0] = "       -|-    ";
	player->shape[6][1] = "*>=====[_]L)";
	player->shape[6][2] = "      -'-`-";

	player->shape[7][0] = "      --|--   ";
	player->shape[7][1] = "*>=====[_]L)";
	player->shape[7][2] = "      -'-`-";

	player->shape[8][0] = "     ---|---  ";
	player->shape[8][1] = "*>=====[_]L)";
	player->shape[8][2] = "      -'-`-";

	player->shape[9][0] = "    ----|---- ";
	player->shape[9][1] = "*>=====[_]L)";
	player->shape[9][2] = "      -'-`-";


	for (int i = 0; i < BulletCount; i++)
	{
		bullets[i] = (Bullet*)malloc(sizeof(Bullet));
		bullets[i]->act = false;
		bullets[i]->x = i;
		bullets[i]->y = 0;
		bullets[i]->color = LIGHTBLUE;
		bullets[i]->shape = "●";
	}


	for (int i = 0; i < EnemyCount; i++)
	{
		enemy[i] = (Enemy*)malloc(sizeof(Enemy));
		enemy[i]->act = true;
		enemy[i]->x = 20;
		enemy[i]->y = rand()%20 + 10;
		enemy[i]->color = YELLOW;
		enemy[i]->shape[0] = "□□□□";
		enemy[i]->shape[1] = "□□□□";
		enemy[i]->shape[2] = "□□□□";
	}

	//enemy = (Enemy*)malloc(sizeof(Enemy));
	//enemy->act = true;
	//enemy->x = 20;
	//enemy->y = 10;
	//enemy->color = YELLOW;
	//enemy->shape[0] = "□□□□";
	//enemy->shape[1] = "□□□□";
	//enemy->shape[2] = "□□□□";

}
int enemyspeed;
void StageProgress()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		player->x--;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		player->x++;

	}
	if (GetAsyncKeyState(VK_UP))
	{
		player->y--;

	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		player->y++;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		for (int i = 0; i < BulletCount; i++)
		{
			if (bullets[i]->act == false)
			{

				bullets[i]->x = player->x + 6;
				bullets[i]->y = player->y + 1;
				bullets[i]->act = true;
				break;
			}
		}
	}

	for (int i = 0; i < BulletCount; i++)
	{
		//if (bullets[i]->act)
		if (bullets[i]->act == true)
		{
			bullets[i]->x++;

			for (int j = 0; j < EnemyCount; j++)
			{
				if (bullets[i]->x >= enemy[j]->x && bullets[i]->x <= enemy[j]->x + 4 && bullets[i]->y >= enemy[j]->y && bullets[i]->y <= enemy[j]->y + 2)
				{
					enemy[j]->x = 40;
				}
			}

			



			if (bullets[i]->x >= 40)
			{
				bullets[i]->x = i;
				bullets[i]->y = 0;
				bullets[i]->act = false;
			}
		}
	}
	enemyspeed++;
	/*if (enemyspeed == 2)
	{
		enemy->x--;
		if (enemy->x == 0) enemy->x = 40;
		enemyspeed = 0;
	}*/
	
	for (int i = 0; i < EnemyCount; i++)
	{
		if ((enemy[i]->x <= (player->x) || (enemy[i]->x <= (player->x + 6))) && ((player->x < enemy[i]->x + 4) || (player->x + 6 < enemy[i]->x + 4)) &&
			((enemy[i]->y <= player->y) || (enemy[i]->y <= player->y + 2)) && ((player->y < enemy[i]->y + 3) || (player->y + 2 < enemy[i]->y + 3)))
		{
			enemy[i]->color = RED;
		}
		else
		{
			enemy[i]->color = YELLOW;
		}
	}
	
}

int stageCount = 0;

void StageRender()
{

	stageCount++;
	if (stageCount == 3)
	{
		player->aniIndex++;

		player->aniIndex %= 10;
		stageCount = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		MovePos(player->x, player->y + i);
		Paint(player->color);
		printf(player->shape[player->aniIndex][i]);
	}


	for (int i = 0; i < EnemyCount; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			MovePos(enemy[i]->x, enemy[i]->y + j);
			Paint(enemy[i]->color);
			printf(enemy[i]->shape[j]);
		}

	}


	for (int i = 0; i < BulletCount; i++)
	{
		MovePos(bullets[i]->x, bullets[i]->y);
		Paint(bullets[i]->color);
		printf(bullets[i]->shape);
	}




}

void StageRelease()
{
	if (player != nullptr)
	{
		free(player);
		player = nullptr;
	}

	for (int i = 0; i < BulletCount; i++)
	{
		if (bullets[i] != nullptr)
		{
			free(bullets[i]);
			bullets[i] = nullptr;
		}
	}

	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] != nullptr)
		{
			free(enemy[i]);
			enemies[i] = nullptr;
		}
	}


}
#pragma endregion

#pragma region WIN_API
void MovePos(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Paint(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void HideCursor()
{

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

}


#pragma endregion
