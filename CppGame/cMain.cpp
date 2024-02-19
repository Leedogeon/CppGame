﻿#include <stdio.h>
#include <Windows.h>

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
	COLOR color;
	const char* shape[2];
};

struct Enemy
{
	bool act;
	int x;
	int y;
	COLOR color;
	const char* shape[3];
};

#pragma endregion


#pragma region Game
Player* player = nullptr;
Enemy* enemy = nullptr;

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
		Sleep(50);

	}

	StageRelease();

	return 0;
}

#pragma region Stage
void StageInitialize()
{

	player = (Player*)malloc(sizeof(Player));
	player->act = true;
	player->x = 5;
	player->y = 5;
	player->color = WHITE;
	player->shape[0] = "＠＠";
	player->shape[1] = "＠＠";

	enemy = (Enemy*)malloc(sizeof(Enemy));
	enemy->act = true;
	enemy->x = 10;
	enemy->y = 10;
	enemy->color = YELLOW;
	enemy->shape[0] = "□□□□";
	enemy->shape[1] = "□□□□";
	enemy->shape[2] = "□□□□";

}

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

	if ((enemy->x <= (player->x)|| (enemy->x <= (player->x+1))) && ((player->x < enemy->x + 4) || (player->x+1 < enemy->x + 4) ) &&
		((enemy->y <= player->y)||(enemy->y <= player->y+1)) && ((player->y < enemy->y + 3)||(player->y+1 < enemy->y + 3)))
	{
		enemy->color = RED;
	}
	else
	{
		enemy->color = YELLOW;
	}
}


void StageRender()
{

	for (int i = 0; i < 3; i++)
	{
		MovePos(enemy->x, enemy->y + i);
		Paint(enemy->color);
		printf(enemy->shape[i]);

	}

	for (int i = 0; i < 2; i++)
	{
		MovePos(player->x, player->y+i);
		Paint(player->color);
		printf(player->shape[i]);
	}
		

	
	
}

void StageRelease()
{
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
