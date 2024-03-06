#include <stdio.h>
#include <Windows.h>
#include <stdlib.h> 
#include <time.h> 
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

int ChooseMap[MapSize][MapSize] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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

enum SceneID
{
	LOGO,
	CHOOSE,
	MAIN,
	SHOP,
	BATTLE,
	OPTION,
	STATUS,
	ENEMYSTATUS,
	END,
};

enum PlayerType
{
	WARRIOR,
	WIZARD,
	ARCHER,
};

//옵션에서 복귀
enum Prev
{
	OPTIONLOGO,
	OPTIONMAIN,
};

#pragma endregion
#pragma region startPage
struct Obj
{
	int x;
	int y;
	const char* shape;
	COLOR color;
};

Obj* selectShape = nullptr;
Obj* startText = nullptr;
Obj* optionText = nullptr;
Obj* exitText = nullptr;

#pragma endregion
SceneID sceneID;
Prev prev;
struct Text
{
	const char* Description[3];
	COLOR color;
};
struct Box
{
	const char* boxShape[3];
};
#pragma region Player

struct Player
{
	int level;
	int maxHp;
	int maxMp;
	int x;
	int y;
	int atk;
	const char* shape[3];
	COLOR color;
	int hp;
	int mp;
	Text text;
	PlayerType playerType;
	bool act;
	bool critical;
};
Player* player = nullptr;
Player* warrior = nullptr;
Player* wizard = nullptr;
Player* archer = nullptr;
Player* Enemy = nullptr;

struct Weapon
{
	int x;
	int y;
	const char* shape[4];
	COLOR color;
	const char* Text;
};
Weapon* playerWeapon = nullptr;
Weapon* warriorWeapon = nullptr;
Weapon* wizardWeapon = nullptr;
Weapon* archerWeapon = nullptr;

struct Skill
{
	int x;
	int y;
	const char* shape;
	COLOR textColor;
	COLOR color;
	const char* Text;
	bool act;
};
Skill* normal = nullptr;
Skill* warriorSkill = nullptr;
Skill* wizardSkill = nullptr;
Skill* archerSkill = nullptr;
Skill* playerSkill = nullptr;
Skill* enemySkill = nullptr;

#pragma endregion
Box* box;
#pragma region Village
struct VillageChoose
{
	const char* name;
	int x;
	int y;
	COLOR color;
};
VillageChoose* VgBATTLE;
VillageChoose* VgESTATUS;
VillageChoose* VgOPTION;
VillageChoose* VgBED;
VillageChoose* VgSTATUS;
VillageChoose* VgEXIT;
#pragma endregion
#pragma region  function
void HideCursor();
void Init();
void InitRelease();
void releaseWizard();
void releaseWarrior();
void releaseArcher();
void MainScreen();
void Option();
void Choose();
void Village();
void Status();
void eStatus();
void Battle();
void returnVillage();
void PlayerView();
void EnemyView();
void Attack(int num);
void End(int num);
void effectRemove(int num);
#pragma endregion
int gameSpeed = 50;
int exitCheck = 0;
int main()
{
	sceneID = LOGO;
	InitBuffer();
	Init();

	while (true)
	{

		switch (sceneID)
		{
		case LOGO: MainScreen();
			break;
		case CHOOSE: Choose();
			break;
		case MAIN: Village();
			break;
		case BATTLE: Battle();
			break;
		case OPTION: Option();
			break;
		case STATUS: Status();
			break;
		case END: End(exitCheck);
			break;
		case ENEMYSTATUS: eStatus();
			break;
		default:
			break;
		}
		FlipBuffer();
		ClearBuffer();
		Sleep(gameSpeed);
	}
	ReleaseBuffer();
}
#pragma region Init
void Init()
{
#pragma region character
	player = (Player*)malloc(sizeof(Player));
	player->shape[0] = "  o  ";
	player->shape[1] = " /|\\  ";
	player->shape[2] = " / \\ ";
	playerWeapon = (Weapon*)malloc(sizeof(Weapon));
	playerWeapon->x = player->x + 2;
	playerWeapon->y = player->y - 2;

	normal = (Skill*)malloc(sizeof(Skill));
	normal->Text = "기본공격";
#pragma region warrior
	warrior = (Player*)malloc(sizeof(Player));
	warrior->text.Description[0] = "전사";
	warrior->text.Description[1] = "높은 기본능력치";
	warrior->text.Description[2] = "기본공격 위주의 캐릭터";
	warrior->text.color = WHITE;
	warrior->maxHp = 30;
	warrior->hp = 30;
	warrior->mp = 5;
	warrior->maxMp = 5;
	warrior->x = 15;
	warrior->y = 7;
	warrior->atk = 10;
	warrior->shape[0] = player->shape[0];
	warrior->shape[1] = player->shape[1];
	warrior->shape[2] = player->shape[2];
	warriorWeapon = (Weapon*)malloc(sizeof(Weapon));
	warriorWeapon->x = warrior->x + 2;
	warriorWeapon->y = warrior->y - 2;
	warriorWeapon->shape[0] = "  /▨";
	warriorWeapon->shape[1] = " /  /";
	warriorWeapon->shape[2] = " ▨/";
	warriorWeapon->shape[3] = "/";
	warriorSkill = (Skill*)malloc(sizeof(Skill));
	warriorSkill->Text = "강타";
	warriorSkill->shape = "";
	warriorSkill->color = WHITE;
#pragma endregion
#pragma region wizard
	wizard = (Player*)malloc(sizeof(Player));
	wizard->text.Description[0] = "마법사";
	wizard->text.Description[1] = "높은 공격력, 낮은 체력";
	wizard->text.Description[2] = "스킬공격 위주의 캐릭터";
	wizard->text.color = WHITE;
	wizard->maxHp = 15;
	wizard->hp = 15;
	wizard->mp = 30;
	wizard->maxMp = 30;
	wizard->atk = 3;
	wizard->x = 15;
	wizard->y = 20;
	wizard->shape[0] = player->shape[0];
	wizard->shape[1] = player->shape[1];
	wizard->shape[2] = player->shape[2];
	wizardWeapon = (Weapon*)malloc(sizeof(Weapon));
	wizardWeapon->x = wizard->x + 2;
	wizardWeapon->y = wizard->y - 2;
	wizardWeapon->shape[0] = "";
	wizardWeapon->shape[1] = "  @";
	wizardWeapon->shape[2] = " /";
	wizardWeapon->shape[3] = "/";

	wizardSkill = (Skill*)malloc(sizeof(Skill));
	wizardSkill->Text = "에너지볼";
	wizardSkill->shape = "＠";
	wizardSkill->color = LIGHTBLUE;
#pragma endregion
#pragma region archer
	archer = (Player*)malloc(sizeof(Player));
	archer->text.Description[0] = "궁수";
	archer->text.Description[1] = "평범한 능력치, 확률성 치명타";
	archer->text.Description[2] = "치명타 공격 캐릭터";
	archer->text.color = WHITE;
	archer->maxHp = 20;
	archer->hp = 20;
	archer->mp = 20;
	archer->maxMp = 20;
	archer->atk = 7;
	archer->x = 15;
	archer->y = 33;
	archer->shape[0] = player->shape[0];
	archer->shape[1] = player->shape[1];
	archer->shape[2] = player->shape[2];
	archerWeapon = (Weapon*)malloc(sizeof(Weapon));
	archerWeapon->x = archer->x + 2;
	archerWeapon->y = archer->y - 1;
	archerWeapon->shape[0] = "";
	archerWeapon->shape[1] = "│\\";
	archerWeapon->shape[2] = "││";
	archerWeapon->shape[3] = "│/";

	archerSkill = (Skill*)malloc(sizeof(Skill));
	archerSkill->Text = "더블샷";
	archerSkill->shape = ">=>";
	archerSkill->color = YELLOW;
#pragma endregion
#pragma region enemy
	Enemy = (Player*)malloc(sizeof(Player));
	Enemy->hp = 30;
	Enemy->mp = 10;
	Enemy->x = 30;
	Enemy->y = 10;
	Enemy->maxHp = 30;
	Enemy->atk = 5;
	Enemy->shape[0] = "┌───┐";
	Enemy->shape[1] = "│ ┼ │";
	Enemy->shape[2] = "└───┘";
	enemySkill = (Skill*)malloc(sizeof(Skill));
	enemySkill->x = Enemy->x - 2;
	enemySkill->y = Enemy->y + 1;
	enemySkill->shape = "※";
	enemySkill->color = RED;
#pragma endregion
#pragma endregion

#pragma region object
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


	box = (Box*)malloc(sizeof(Box));
	box->boxShape[0] = "┌──────────┐";
	box->boxShape[1] = "│          │";
	box->boxShape[2] = "└──────────┘";


	VgBATTLE = (VillageChoose*)malloc(sizeof(VillageChoose));
	VgBATTLE->name = "전투";
	VgBATTLE->x = 22;
	VgBATTLE->y = 6;
	VgBATTLE->color = WHITE;

	VgESTATUS = (VillageChoose*)malloc(sizeof(VillageChoose));
	VgESTATUS->name = "적정보";
	VgESTATUS->x = 22;
	VgESTATUS->y = 16;
	VgESTATUS->color = WHITE;

	VgOPTION = (VillageChoose*)malloc(sizeof(VillageChoose));
	VgOPTION->name = "옵션";
	VgOPTION->x = 22;
	VgOPTION->y = 26;
	VgOPTION->color = WHITE;

	VgBED = (VillageChoose*)malloc(sizeof(VillageChoose));
	VgBED->name = "휴식";
	VgBED->x = 32;
	VgBED->y = 6;
	VgBED->color = WHITE;

	VgSTATUS = (VillageChoose*)malloc(sizeof(VillageChoose));
	VgSTATUS->name = "능력치";
	VgSTATUS->x = 32;
	VgSTATUS->y = 16;
	VgSTATUS->color = WHITE;

	VgEXIT = (VillageChoose*)malloc(sizeof(VillageChoose));
	VgEXIT->name = "종료";
	VgEXIT->x = 32;
	VgEXIT->y = 26;
	VgEXIT->color = WHITE;
#pragma endregion
	
}
void InitRelease()
{
	if (player->playerType == WARRIOR)
	{
		releaseArcher();
		releaseWizard();
	}
	if (player->playerType == WIZARD)
	{
		releaseArcher();
		releaseWarrior();

	}
	if (player->playerType == ARCHER)
	{
		releaseWizard();
		releaseWarrior();
	}
}
#pragma endregion
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
	WriteBuffer(15, 35, "ENTER키로 선택", WHITE);



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


	if (GetAsyncKeyState(VK_RETURN))
	{
		if (selectShape->y == startText->y)
		{
			sceneID = CHOOSE;
			selectShape->x = 7;
			selectShape->y = 7;
		}
		if (selectShape->y == optionText->y)
		{
			prev = OPTIONLOGO;
			sceneID = OPTION;
		}
		if (selectShape->y == exitText->y)
		{
			sceneID = END;
			exitCheck = 1;
		}

	}

}
int changeSpeed = gameSpeed;
void Option() {


	WriteBuffer(15, 15, "게임 속도 선택", WHITE);

	WriteBuffer(16, 20, "-", WHITE);
	WriteBuffer(20, 20, "-", WHITE);

	WriteBuffer(13, 24, "방향키 위 아래로 변경", WHITE);
	WriteBuffer(13, 26, "ENTER키로 설정", WHITE);
	WriteBuffer(13, 28, "높을수록 느려집니다", WHITE);


	char sNum[5];

	_itoa_s(changeSpeed, sNum, 10);

	WriteBuffer(18, 20, sNum, WHITE);

	if (GetAsyncKeyState(VK_UP) && changeSpeed < 90)
	{
		changeSpeed += 10;
	}
	if (GetAsyncKeyState(VK_DOWN) && changeSpeed > 30)
	{
		changeSpeed -= 10;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		gameSpeed = changeSpeed;
		if (prev == OPTIONLOGO)
			sceneID = LOGO;
		else if (prev == OPTIONMAIN)
			sceneID = MAIN;
	}
}
void Choose()
{

	for (int y = 0; y < MapSize; y++)
	{
		for (int x = 0; x < MapSize; x++)
		{
			switch (ChooseMap[y][x])
			{
			case 1:
				WriteBuffer(x, y, "■", YELLOW);
				break;

			default:
				break;
			}
		}
	}
	WriteBuffer(13, 1, "SPACE키로 직업을 선택하세요", WHITE);


	WriteBuffer(warrior->x - 5, warrior->y, warrior->text.Description[0], warrior->text.color);
	WriteBuffer(warrior->x + 5, warrior->y + 1, warrior->text.Description[1], warrior->text.color);
	WriteBuffer(warrior->x + 5, warrior->y + 2, warrior->text.Description[2], warrior->text.color);
	WriteBuffer(wizard->x - 5, wizard->y, wizard->text.Description[0], wizard->text.color);
	WriteBuffer(wizard->x + 5, wizard->y + 1, wizard->text.Description[1], wizard->text.color);
	WriteBuffer(wizard->x + 5, wizard->y + 2, wizard->text.Description[2], wizard->text.color);
	WriteBuffer(archer->x - 5, archer->y, archer->text.Description[0], archer->text.color);
	WriteBuffer(archer->x + 5, archer->y + 1, archer->text.Description[1], archer->text.color);
	WriteBuffer(archer->x + 5, archer->y + 2, archer->text.Description[2], archer->text.color);
	if (selectShape->y == warrior->y) warrior->text.color = RED;
	else warrior->text.color = WHITE;
	if (selectShape->y == wizard->y) wizard->text.color = RED;
	else wizard->text.color = WHITE;
	if (selectShape->y == archer->y) archer->text.color = RED;
	else archer->text.color = WHITE;



	for (int i = 0; i < 3; i++)
	{
		WriteBuffer(warrior->x, warrior->y + i, warrior->shape[i], WHITE);
	}
	for (int i = 0; i < 4; i++)
	{
		WriteBuffer(warriorWeapon->x, warriorWeapon->y + i, warriorWeapon->shape[i], WHITE);
	}

	for (int i = 0; i < 3; i++)
	{
		WriteBuffer(wizard->x, wizard->y + i, wizard->shape[i], WHITE);
	}
	for (int i = 0; i < 4; i++)
	{
		WriteBuffer(wizardWeapon->x, wizardWeapon->y + i, wizardWeapon->shape[i], WHITE);
	}

	for (int i = 0; i < 3; i++)
	{
		WriteBuffer(archer->x, archer->y + i, archer->shape[i], WHITE);
	}
	for (int i = 0; i < 4; i++)
	{
		WriteBuffer(archerWeapon->x, archerWeapon->y + i, archerWeapon->shape[i], WHITE);
	}




	WriteBuffer(selectShape->x, selectShape->y, selectShape->shape, selectShape->color);

	if (GetAsyncKeyState(VK_DOWN) && selectShape->y < 30)
	{
		selectShape->y += 13;
	}
	if (GetAsyncKeyState(VK_UP) && selectShape->y > 10)
	{
		selectShape->y -= 13;
	}


	if (GetAsyncKeyState(VK_SPACE))
	{
		if (selectShape->y == warrior->y)
		{
			player = warrior;
			player->playerType = WARRIOR;
			playerWeapon = warriorWeapon;
			playerSkill = warriorSkill;
		}
		if (selectShape->y == wizard->y)
		{
			player = wizard;
			player->playerType = WIZARD;
			playerWeapon = wizardWeapon;
			playerSkill = wizardSkill;
		}
		if (selectShape->y == archer->y)
		{
			player = archer;
			player->playerType = ARCHER;
			playerWeapon = archerWeapon;
			playerSkill = archerSkill;
		}
		player->x = 5;
		player->y = 10;
		playerWeapon->x = player->x + 2;
		if (player->playerType != ARCHER)
			playerWeapon->y = player->y - 2;
		else playerWeapon->y = player->y - 1;

		effectRemove(1);

		player->level = 1;
		player->critical = false;
		playerSkill->act = false;
		playerSkill->textColor = WHITE;
		returnVillage();
		InitRelease();

	}
}
#pragma region release
void releaseWarrior()
{
	if (warrior != nullptr)
	{
		free(warrior);
		warrior = nullptr;
	}
	if (warriorWeapon != nullptr)
	{
		free(warriorWeapon);
		warriorWeapon = nullptr;
	}
	if (warriorSkill != nullptr)
	{
		free(warriorSkill);
		warriorSkill = nullptr;
	}
}
void releaseWizard()
{
	if (wizard != nullptr)
	{
		free(wizard);
		wizard = nullptr;
	}
	if (wizardWeapon != nullptr)
	{
		free(wizardWeapon);
		wizardWeapon = nullptr;
	}
	if (wizardSkill != nullptr)
	{
		free(wizardSkill);
		wizardSkill = nullptr;
	}
}
void releaseArcher()
{
	if (archer != nullptr)
	{
		free(archer);
		archer = nullptr;
	}
	if (archerWeapon != nullptr)
	{
		free(archerWeapon);
		archerWeapon = nullptr;
	}
	if (archerSkill != nullptr)
	{
		free(archerSkill);
		archerSkill = nullptr;
	}
}
#pragma endregion
void Village()
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
	PlayerView();

	for (int k = 0; k < 2; k++)
	{

		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				WriteBuffer(20 + k * 10, 5 + i + j * 10, box->boxShape[i], WHITE);
			}
		}
	}

	WriteBuffer(VgBATTLE->x, VgBATTLE->y, VgBATTLE->name, VgBATTLE->color);
	WriteBuffer(VgESTATUS->x, VgESTATUS->y, VgESTATUS->name, VgESTATUS->color);
	WriteBuffer(VgOPTION->x, VgOPTION->y, VgOPTION->name, VgOPTION->color);
	WriteBuffer(VgBED->x, VgBED->y, VgBED->name, VgBED->color);
	WriteBuffer(VgSTATUS->x, VgSTATUS->y, VgSTATUS->name, VgSTATUS->color);
	WriteBuffer(VgEXIT->x, VgEXIT->y, VgEXIT->name, VgEXIT->color);

	WriteBuffer(selectShape->x, selectShape->y, selectShape->shape, WHITE);

	if (GetAsyncKeyState(VK_DOWN) && selectShape->y < 26)
	{
		selectShape->y += 10;
	}
	if (GetAsyncKeyState(VK_UP) && selectShape->y > 6)
	{
		selectShape->y -= 10;
	}
	if (GetAsyncKeyState(VK_RIGHT) && selectShape->x < 28)
	{
		selectShape->x += 10;
	}
	if (GetAsyncKeyState(VK_LEFT) && selectShape->x > 18)
	{
		selectShape->x -= 10;
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		if (VgBATTLE->y == selectShape->y && selectShape->x < 20)
		{
			sceneID = BATTLE;
			selectShape->x = 4;
			selectShape->y = 31;
			player->act = true;
			Enemy->act = false;
		}
		if (VgESTATUS->y == selectShape->y && selectShape->x < 20)
		{
			sceneID = ENEMYSTATUS;
		}
		if (VgOPTION->y == selectShape->y && selectShape->x < 20)
		{
			prev = OPTIONMAIN;
			sceneID = OPTION;
		}
		if (VgBED->y == selectShape->y && selectShape->x > 20)
		{
			player->hp = player->maxHp;
			player->mp = player->maxMp;
		}
		if (VgSTATUS->y == selectShape->y && selectShape->x > 20)
		{
			sceneID = STATUS;

		}
		if (VgEXIT->y == selectShape->y && selectShape->x > 20)
		{
			sceneID = END;
			exitCheck = 1;
		}
	}


#pragma region COLOR
	if (VgBATTLE->y == selectShape->y && selectShape->x < 20)
	{
		VgBATTLE->color = RED;
	}
	else VgBATTLE->color = WHITE;
	if (VgESTATUS->y == selectShape->y && selectShape->x < 20)
	{
		VgESTATUS->color = RED;
	}
	else VgESTATUS->color = WHITE;
	if (VgOPTION->y == selectShape->y && selectShape->x < 20)
	{
		VgOPTION->color = RED;
	}
	else VgOPTION->color = WHITE;
	if (VgBED->y == selectShape->y && selectShape->x > 20)
	{
		VgBED->color = RED;
	}
	else VgBED->color = WHITE;
	if (VgSTATUS->y == selectShape->y && selectShape->x > 20)
	{
		VgSTATUS->color = RED;
	}
	else VgSTATUS->color = WHITE;
	if (VgEXIT->y == selectShape->y && selectShape->x > 20)
	{
		VgEXIT->color = RED;
	}
	else VgEXIT->color = WHITE;
#pragma endregion


}
int levelcnt = 0;
void Battle()
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


	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			WriteBuffer(5 + j * 10, 30 + i, box->boxShape[i], WHITE);
		}
	}

	PlayerView();
	EnemyView();
	WriteBuffer(6, 31, normal->Text, normal->color);
	WriteBuffer(16, 31, playerSkill->Text, playerSkill->textColor);
	WriteBuffer(selectShape->x, selectShape->y, selectShape->shape, selectShape->color);

	if (player->act == true)
	{
		if (GetAsyncKeyState(VK_LEFT) && selectShape->x > 4)
		{
			selectShape->x -= 10;

		}

		if (GetAsyncKeyState(VK_RIGHT) && selectShape->x < 14)
		{
			selectShape->x += 10;
		}

		if (selectShape->x < 10)  normal->color = RED;
		else normal->color = WHITE;
		if (selectShape->x > 10)  playerSkill->textColor = RED;
		else playerSkill->textColor = WHITE;


		if (GetAsyncKeyState(VK_RETURN) && player->act == true)
		{
			if (selectShape->x < 10)
			{
				Attack(1);
				player->act = false;
				Enemy->act = true;
			}
			if (selectShape->x > 10)
			{
				if (player->mp >= 5)
				{
					playerSkill->act = true;
					player->act = false;
				}
				else WriteBuffer(16, 29, "MP부족", RED);
			}
		}
	}


	if (playerSkill->act == true)
	{
		WriteBuffer(playerSkill->x, playerSkill->y, playerSkill->shape, playerSkill->color);
		playerSkill->x++;
		if (playerSkill->x == Enemy->x)
		{
			Attack(2);
			playerSkill->act = false;
			effectRemove(1);
			Enemy->act = true;
		}
	}


	if (Enemy->hp <= 0)
	{
		Enemy->act = false;
		returnVillage();
		levelcnt++;
		if (levelcnt == 3)
		{
			player->maxHp += 1;
			player->maxMp += 1;
			player->hp = player->maxHp;
			player->mp = player->maxMp;
			player->level++;
			levelcnt = 0;
			Enemy->maxHp += 3;
			Enemy->atk += 1;
			if (player->level % 2 == 0) player->atk++;

		}
		Enemy->hp = Enemy->maxHp;
	}


	if (Enemy->act == true)
	{
		enemySkill->act = true;
		Enemy->act = false;
	}

	if (enemySkill->act == true)
	{
		WriteBuffer(enemySkill->x, enemySkill->y, enemySkill->shape, enemySkill->color);
		enemySkill->x--;
		if (enemySkill->x == player->x)
		{
			Attack(3);
			enemySkill->act = false;
			effectRemove(2);
			player->act = true;
		}
	}


	if (player->hp <= 0)
	{
		sceneID = END;
		exitCheck = 2;
	}

}
void End(int num)
{
	if (num == 1)
	{
		WriteBuffer(16, 20, "게임을 종료합니다", WHITE);
	}

	if (num == 2)
	{
		WriteBuffer(14, 20, "플레이어가 사망하였습니다", RED);
	}
	WriteBuffer(16, 30, "ESC로 게임 종료", WHITE);

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		exit(0);
	}
}
void Attack(int num)
{

	if (num < 3 && player->playerType == ARCHER)
	{
		srand(time(NULL));
		int dice = rand() % 6 + 1;
		if (dice > 3)
		{
			WriteBuffer(15, 5, "CRITICAL!", YELLOW);
			player->critical = true;
		}

	}

	if (num == 1)
	{

		if (player->critical == true)
		{
			Enemy->hp -= player->atk * 2;
			player->critical = false;
		}
		else Enemy->hp -= player->atk;


	}

	if (num == 2)
	{
		if (player->critical == true)
		{
			Enemy->hp -= player->atk * 4;
			player->critical = false;
		}

		if (player->playerType == WIZARD) Enemy->hp -= player->atk * 5;
		else Enemy->hp -= player->atk * 2;

		player->mp -= 5;
	}


	if (num == 3)
	{
		player->hp -= Enemy->atk;
	}



}
void effectRemove(int num)
{
	if (num == 1)
	{
		playerSkill->x = player->x + 4;
		playerSkill->y = player->y + 1;
	}

	if (num == 2)
	{
		enemySkill->x = Enemy->x - 2;
		enemySkill->y = Enemy->y + 1;
	}

}
void returnVillage()
{
	selectShape->x = 18;
	selectShape->y = 6;
	sceneID = MAIN;
}
#pragma region  stat&view
void Status()
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

	PlayerView();
	WriteBuffer(player->x - 1, player->y + 9, "기술", WHITE);
	WriteBuffer(player->x - 1, player->y + 10, normal->Text, WHITE);
	WriteBuffer(player->x - 1, player->y + 11, playerSkill->Text, WHITE);

	if (GetAsyncKeyState(VK_RETURN))
	{
		sceneID = MAIN;
	}


	WriteBuffer(15, 35, "ENTER키로 돌아가기", WHITE);

}
void eStatus()
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

	EnemyView();
	if (GetAsyncKeyState(VK_RETURN))
	{
		sceneID = MAIN;
	}


	WriteBuffer(15, 35, "ENTER키로 돌아가기", WHITE);
}

void PlayerView()
{
	for (int i = 0; i < 3; i++)
	{
		WriteBuffer(player->x, player->y + i, player->shape[i], WHITE);
	}
	for (int i = 0; i < 4; i++)
	{
		WriteBuffer(playerWeapon->x, playerWeapon->y + i, playerWeapon->shape[i], WHITE);
	}

	char sNum[5];

	WriteBuffer(player->x - 1, player->y - 5, "Level : ", WHITE);
	_itoa_s(player->level, sNum, 10);
	WriteBuffer(player->x + 3, player->y - 5, sNum, WHITE);
	_itoa_s(player->hp, sNum, 10);
	WriteBuffer(player->x - 1, player->y + 5, "HP : ", WHITE);
	WriteBuffer(player->x + 2, player->y + 5, sNum, WHITE);
	_itoa_s(player->mp, sNum, 10);
	WriteBuffer(player->x - 1, player->y + 6, "MP : ", WHITE);
	WriteBuffer(player->x + 2, player->y + 6, sNum, WHITE);
	_itoa_s(player->atk, sNum, 10);
	WriteBuffer(player->x - 3, player->y + 7, "공격력 : ", WHITE);
	WriteBuffer(player->x + 2, player->y + 7, sNum, WHITE);
}
void EnemyView()
{
	for (int i = 0; i < 3; i++)
	{
		WriteBuffer(Enemy->x, Enemy->y + i, Enemy->shape[i], WHITE);
	}

	char sNum[5];

	_itoa_s(Enemy->hp, sNum, 10);
	WriteBuffer(Enemy->x - 1, Enemy->y + 5, "HP : ", WHITE);
	WriteBuffer(Enemy->x + 2, Enemy->y + 5, sNum, WHITE);
	_itoa_s(Enemy->atk, sNum, 10);
	WriteBuffer(Enemy->x - 3, Enemy->y + 6, "공격력 : ", WHITE);
	WriteBuffer(Enemy->x + 2, Enemy->y + 6, sNum, WHITE);
}
#pragma endregion
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