//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//2019.12.03 (v2.0)점수 추가, 충돌처리 추가.
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdbool.h>
#include<time.h>
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

void DrawDion(int dinoY)//공룡 그리는 함수
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
	
	if (legFlag)
	{
		printf("      $$ $$$$   \n");
		printf("      $$          \n");
		printf("      $$$          ");
		legFlag = false;
	}
	else
	{
		printf("        $$$$ $$    \n");
		printf("             $$      \n");
		printf("             $$$      ");
		legFlag = true;
	}
}

void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("  $  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" $$$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf("$$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf("  $  ");
}
//(v2.0)충돌 했을 때, 게임 오버 그려줌
void DrawGameOver(const int score)
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("===========================");
	GotoXY(x, y+1);
	printf("===== G A M E O V E R =====");
	GotoXY(x, y+2);
	printf("===========================");
	GotoXY(x, y+3);
	printf("SCORE : %d", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}
//(v2.0)충돌했으면 true, 아니면 false
bool isCollision(const int treeX, const int dinoY)
{
	//트리의 x가 공룡의 몸체쪽에 있을때, 공룡의 높이가 풍분하지 않다면 충돌로 처리
	GotoXY(0, 0);
	printf("treeX : %d, dinoY : %d", treeX, dinoY);
	if (treeX <= 8 && treeX >= 4 && dinoY > 8)
		return true;
	return false;
}


int main(void)
{
	SetConsoleView();

	while (true)//(v2.0) 게임 루프
	{
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;

		int score = 0;
		clock_t start, curr;//점수 변수 초기화
		start = clock();//시작시간 초기화

		while (true)//한판에 대한 루프
		{
			//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
			if (isCollision(treeX, dinoY))
				break;
			//w키가 늘렸고, 바닥이 아닐때 점프
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
			//(v2.0)
			curr = clock();//현재시간 받아오기
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)//1초가 넘었을 때
			{
				score++;//스코어 up
				start = clock();//시작시간 초기화
			}
			Sleep(130);
			system("cls");//clear

			//(v2.0) 점수출력을 1초마다 해주는 것이 아니라 항상 출력해주면서, 1초가 지났을 때 ++해줌
			//커서를 가운대 위쪽으로 옮긴다. 콘솔창이 cols=100이니깐 2*x이므로 22정도 넣어줌
			GotoXY(22, 0);
			printf("Score : %d", score);//점수출력
		}
		DrawGameOver(score);
		system("pause");
		return 0;
	}
}

