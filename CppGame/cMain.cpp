#include <stdio.h>
#include <Windows.h>

#pragma region Map
#define MapSize 40
int map[MapSize][MapSize] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

};
#pragma endregion

#pragma region Buffer
#define BufferWidth 80	  //가로 버퍼 크기
#define BufferHeight 40	  //세로 버퍼 크기
HANDLE hBuffer[2];	// 창 두개를 제어하는 핸들
int screeIndex;		//hBuffer[screeIndex], screenIndex == 0 or 1
void InitBuffer();
void FlipBuffer();
void ClearBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void ReleaseBuffer();
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


struct Obj
{
	int x;
	int y;
	const char* shape;
	int color;
};

Obj* selectShape = nullptr;
Obj* startText = nullptr;
Obj* optionText = nullptr;
Obj* exitText = nullptr;


void MovePos(int x, int y);
void Paint(int color);
void HideCursor();

void Init();
void MainScreen();
int main()
{
	HideCursor();
	InitBuffer();
	Init();

	while (true)
	{
		MainScreen();
		FlipBuffer();
		ClearBuffer();

		Sleep(30);
	}

	ReleaseBuffer();
}

void Init()
{
	selectShape = (Obj*)malloc(sizeof(Obj));
	selectShape->x = 17;
	selectShape->y = 19;
	selectShape->shape = "☞";
	selectShape->color = WHITE;

	startText = (Obj*)malloc(sizeof(Obj));
	startText->x = 19;
	startText->y = 19;
	startText->shape = "START";
	startText->color = WHITE;

	optionText = (Obj*)malloc(sizeof(Obj));
	optionText->x = 19;
	optionText->y = 21;
	optionText->shape = "OPTION";
	optionText->color = WHITE;

	exitText = (Obj*)malloc(sizeof(Obj));
	exitText->x = 19;
	exitText->y = 23;
	exitText->shape = "EXIT";
	exitText->color = WHITE;

}
void MainScreen()
{
	for (int y = 0; y < MapSize; y++)
	{
		for (int x = 0; x < MapSize; x++)
		{
			switch (map[y][x])
			{
			case 1:
				WriteBuffer(x, y, "■", YELLOW);
				break;

			default:
				break;
			}
		}
	}
	WriteBuffer(selectShape->x, selectShape->y, selectShape->shape, selectShape->color);
	WriteBuffer(startText->x, startText->y, startText->shape, startText->color);
	WriteBuffer(optionText->x, optionText->y, optionText->shape, optionText->color);
	WriteBuffer(exitText->x, exitText->y, exitText->shape, exitText->color);

	if (GetAsyncKeyState(VK_DOWN) && selectShape->y < exitText->y)
	{
		selectShape->y += 2;
	}
	if (GetAsyncKeyState(VK_UP) && selectShape->y > startText->y)
	{
		selectShape->y -= 2;
	}

	if (selectShape->y == startText->y)	startText->color = RED;
	else startText->color = WHITE;
	if (selectShape->y == optionText->y) optionText->color = RED;
	else optionText->color = WHITE;
	if (selectShape->y == exitText->y) exitText->color = RED;
	else exitText->color = WHITE;


	if (GetAsyncKeyState(VK_SPACE))
	{
		if (selectShape->y == startText->y)
		{

		}
		if (selectShape->y == optionText->y)
		{

		}
		if (selectShape->y == exitText->y)
		{
			printf("프로그램이 종료되었습니다.");
			exit(0);
		}
	}


}




#pragma region Buffer
void InitBuffer()
{
	//현재 스크린 index값은 0
	screeIndex = 0;

	//size.x = 80, size.y = 40 : 화면크기
	COORD size = { BufferWidth, BufferHeight };

	//창 크기 왼쪽 : 0, 위쪽 : 0, 오른쪽 : 80 - 1, 아래쪽 : 40 - 1 
	SMALL_RECT rect = { 0, 0, BufferWidth - 1, BufferHeight - 1 };

	//0번 버퍼 만들기
	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//0번 화면 버퍼 사이즈 설정(만든 버퍼 주소, 크기)
	SetConsoleScreenBufferSize(hBuffer[0], size);
	//0번 창 사이즈 설정
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	//1번 버퍼 만들기
	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//1번 화면 버퍼 사이즈 설정(만든 버퍼 주소, 크기)
	SetConsoleScreenBufferSize(hBuffer[1], size);
	//1번 창 사이즈 설정
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	//커서 정보 등록 : 깜박이는 커서 안보이게
	CONSOLE_CURSOR_INFO info;	//콘솔 커서 정보 구조체
	info.dwSize = 1;			//커서 크기
	info.bVisible = FALSE;		//커서 안보이게

	//0 && 1 각각의 버퍼에 커서 정보 등록
	SetConsoleCursorInfo(hBuffer[0], &info);
	SetConsoleCursorInfo(hBuffer[1], &info);
}

void FlipBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[screeIndex]);

	screeIndex = !screeIndex;
}

void ClearBuffer()
{
	COORD pos = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[screeIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

void WriteBuffer(int x, int y, const char* shape, int color)
{
	COORD pos = { x * 2,y };

	SetConsoleCursorPosition(hBuffer[screeIndex], pos);
	SetConsoleTextAttribute(hBuffer[screeIndex], color);

	DWORD dw;

	WriteFile(hBuffer[screeIndex], shape, strlen(shape), &dw, NULL);
}

void ReleaseBuffer()
{
	//버퍼 닫기
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
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