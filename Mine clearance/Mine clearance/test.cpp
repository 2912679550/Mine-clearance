#define _CRT_SECURE_NO_WARNINGS 1
#include"gmae.h"
void menu()
{
	printf("***************************************\n");
	printf("**************  1.start ***************\n");
	printf("**************  0.exit  ***************\n");
	printf("***************************************\n");
}
void game()
{
	//printf("THE GAME Mine clearance will START SOON!!!\n");
	//雷的信息 的存储
	//布置好雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	initBoard(mine, ROWS, COLS,'0');
	initBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//displayBoard(mine, ROW, COL);
	displayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//扫雷
	//displayBoard(mine, ROW, COL);
	findMine(mine,show,ROW,COL);

}
void text()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("please choose:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			printf("game over\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);

}

int main()
{
	text();
	return 0;
}