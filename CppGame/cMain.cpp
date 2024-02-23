#include<stdio.h>
#include<malloc.h>
#include<Windows.h>

#pragma region define
#define EnemyCount 10
#define ObjSize 4
#define BulletCount 10
#pragma endregion


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
#pragma region print
void MovePos(int x, int y);
void Paint(int color);
void HideCursor();
#pragma endregion


#pragma region struct
struct Obj
{
	int x;
	int y;
	int hp;
	const char* shape[ObjSize];
	bool act;
	COLOR color;
	int speed;
};

struct Bullet
{
	int x;
	int y;
	const char* shape;
	bool act;
	COLOR color;
	int speed;
};
#pragma endregion

Obj* player = nullptr;
Obj* enemies[EnemyCount] = {};
Bullet* playerBullet[BulletCount] = {};
Bullet* enemyBullet[EnemyCount] = {};

void Screen();
void Stage();
void Play();
int main() {
	HideCursor();
	Screen();

	while (true)
	{
		system("cls");
		Play();
		Stage();
		Sleep(20);


	}

	return 0;
}


void Screen()
{
	player = (Obj*)malloc(sizeof(Obj));
	player->x = 0;
	player->y = 10;
	player->shape[0] = "┌──────┐";
	player->shape[1] = "└─┐    └┐  ";
	player->shape[2] = "┌─┘    ┌┘ ";
	player->shape[3] = "└──────┘";
	player->color = YELLOW;

	for (int i = 0; i < BulletCount; i++)
	{
		playerBullet[i] = (Bullet*)malloc(sizeof(Bullet));
		playerBullet[i]->act = false;
		playerBullet[i]->x = i;
		playerBullet[i]->y = 0;
		playerBullet[i]->shape = "●";
		playerBullet[i]->color = WHITE;

	}

	for (int i = 0; i < EnemyCount; i++)
	{
		enemies[i] = (Obj*)malloc(sizeof(Obj));
		enemies[i]->x = rand() % 10 + 20;
		enemies[i]->y = rand() % 20 + 5;
		enemies[i]->act = true;
		enemies[i]->shape[0] = "┌──┐";
		enemies[i]->shape[1] = "┃╂ ┃";
		enemies[i]->shape[2] = "┃  ┃";
		enemies[i]->shape[3] = "└──┘";
		enemies[i]->color = (COLOR)(rand() % 14 + 1);

		enemyBullet[i] = (Bullet*)malloc(sizeof(Bullet));
		enemyBullet[i]->shape = "◎";
		enemyBullet[i]->act = false;
		enemyBullet[i]->color = RED;
		enemyBullet[i]->speed = 0;
	}


}
void Play()
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
			if (playerBullet[i]->act == false)
			{

				playerBullet[i]->x = player->x + 5;
				playerBullet[i]->y = player->y + 2;
				playerBullet[i]->act = true;
				break;
			}
		}
	}

	for (int i = 0; i < BulletCount; i++)
	{
		if (playerBullet[i]->act == true)
		{
			playerBullet[i]->x++;


			if (playerBullet[i]->x >= 40)
			{
				playerBullet[i]->x = i;
				playerBullet[i]->y = 0;
				playerBullet[i]->act = false;
			}
		}
	}



	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemyBullet[i]->act == false)
		{

			enemyBullet[i]->x = enemies[i]->x - 1;
			enemyBullet[i]->y = enemies[i]->y + 1;
			enemyBullet[i]->act = true;
			break;
		}
	}



	for (int i = 0; i < EnemyCount; i++)
	{

		if (enemyBullet[i]->act == true)
		{
			enemyBullet[i]->x--;


			if (enemyBullet[i]->x <= 0)
			{
				enemyBullet[i]->x = enemies[i]->x - 1;
				enemyBullet[i]->y = enemies[i]->y + 1;
				enemyBullet[i]->act = false;
			}

		}


	}




}

void Stage()
{

	for (int i = 0; i < ObjSize; i++)
	{
		MovePos(player->x, player->y + i);
		printf(player->shape[i]);
	}

	for (int i = 0; i < BulletCount; i++)
	{
		MovePos(playerBullet[i]->x, playerBullet[i]->y);
		printf(playerBullet[i]->shape);
	}

	for (int i = 0; i < EnemyCount; i++)
	{
		for (int j = 0; j < ObjSize; j++)
		{
			MovePos(enemies[i]->x, enemies[i]->y + j);
			printf(enemies[i]->shape[j]);
		}
		MovePos(enemyBullet[i]->x, enemyBullet[i]->y);
		printf(enemyBullet[i]->shape);
	}




}








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
