#include<stdio.h>
#include<malloc.h>
#include<Windows.h>

#pragma region define
#define EnemyCount 10
#define ObjSize 4
#define BulletCount 10
#pragma endregion

int map[10][10] =
{
	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,
};


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
void screen();
void Init();
void Play();
struct Player
{
	int x;
	int y;
	const char* shape;
	bool fall;
};
Player* player = nullptr;

int main() {
	HideCursor();
	Init();
	while (true)
	{
		system("cls");
		screen();
		
		MovePos(player->x, player->y);
		printf(player->shape);

		Play();
		Sleep(20);
	}

	return 0;
}

void screen() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}

	MovePos(0, 20);
	for (int i = 0; i < 20; i++)
	{
		printf("＃");
	}
}
void Init()
{
	player = (Player*)malloc(sizeof(Player));
	player->x = 10;
	player->y = 10;
	player->shape = "옷";
	player->fall = true;
}


void Play()
{
	if (player->fall == true)
	{
		player->y++;
	}
	
	if (player->y == 20)
	{
		player->fall == false;
		player->y = 19;
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
