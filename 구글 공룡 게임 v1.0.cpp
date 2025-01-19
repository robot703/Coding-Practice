#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdbool.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

void SetConsoleView()//콘송 창의 크기와 제목을 지정하는 함수
{
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaurs. By BlockDMask");
}

void GotoXY(int x, int y)//커서의 위치를 x,y로 이동하는 함수
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown()//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

void DrawDion(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	static bool fire = true;

	printf("          $$$$$$$ \n");
	printf("         $$ $$$$$$\n");
	printf("  $      $$$$$$$$$"); 
	if (fire)
	{
		printf("         $$$ $$$  $\n");
		fire = false;
	}
	else
	{
		printf(" \n");
		fire = true;
	}
	printf("  $      $$$      "); 
	if (fire) {
		printf("\n");
		fire = false;
	}
	else
	{
		printf("    $$ $$$ $$$ $$  $\n");
		fire = true;
	}
	printf("  $$     $$$$$$$  "); 
	if (fire)
	{
		printf("         $$$ $$$$$$\n");
		fire = false;
	}
	else
	{
		printf("\n");
		fire = true;
	}
	printf("   $$   $$$$$     \n");
	printf("   $$  $$$$$$$$$$ \n");
	printf("    $$$$$$$$$$    \n");
	printf("    $$$$$$$$$$    \n");
	printf("      $$$$$$$$    \n");
	printf("       $$$$$$     \n");
	if (legFlag)
	{
		printf("       $   $$$   \n");
		printf("       $$          ");
		legFlag = false;
	}
	else
	{
		printf("       $$$   $     \n");
		printf("             $$      ");
		legFlag = true;
	}
}

	void DrawTree(int treeX)
	{
		GotoXY(treeX, TREE_BOTTOM_Y );
		printf("  $  ");
		GotoXY(treeX, TREE_BOTTOM_Y + 1);
		printf(" $$$ ");
		GotoXY(treeX, TREE_BOTTOM_Y + 2);
		printf("$$$$$");
		GotoXY(treeX, TREE_BOTTOM_Y + 3);
		printf("  $  ");
	}

	int main(void)
	{
		SetConsoleView();

		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;

		while (true)
		{
			if (GetKeyDown() == 'w' && isBottom)//z키가 눌렸고, 바닥이 아닐때만 점프가능.
			{
				isJumping = true;
				isBottom = false;
			}

			if (isJumping)//점프중이면 y감소
			{
				dinoY -= gravity;
			}
			else//점프끝이면 y증가
			{
				dinoY += gravity;
			}
			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
			//Y가 증가한다는 것은 공룡이 아래로 내려온다는 뜻.
			if (dinoY >= DINO_BOTTOM_Y)
			{
				dinoY = DINO_BOTTOM_Y;
				isBottom = true;
			}

			//점프의 맨위를 찍으면 점프가 끝난 상황
			if (dinoY <= 3)
			{
				isJumping = false;
			}

			//나무가 왼쪽으로 가도록 하고(x의 음수 방향)
			//나무의 위치가 왼쪽 끝으로가면 다시 초기 위치로 소환
			treeX -= 2;
			if (treeX <= 0)
			{
				treeX = TREE_BOTTOM_X;
			}

			DrawDion(dinoY);//draw dino
			DrawTree(treeX);//draw tree
			Sleep(130);
			system("cls");//clear
		}
		system("pause");
		return 0;
	}

	