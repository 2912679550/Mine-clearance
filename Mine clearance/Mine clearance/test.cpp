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
	//�׵���Ϣ �Ĵ洢
	//���ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	initBoard(mine, ROWS, COLS,'0');
	initBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//displayBoard(mine, ROW, COL);
	displayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//ɨ��
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
			printf("�����������������\n");
			break;
		}

	} while (input);

}

int main()
{
	text();
	return 0;
}