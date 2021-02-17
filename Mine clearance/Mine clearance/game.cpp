#define _CRT_SECURE_NO_WARNINGS 1
#include"gmae.h"

void initBoard(char board[ROWS][COLS], int rows, int cols,char input)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = input;
		}
	}

}


void displayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row*col-EASY_COUNT)
	{
		printf("�������Ų���׵����꣺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//����
			if (mine[x][y] == '1')
			{
				printf("���ź�����GG�ˣ���������\n");
				displayBoard(mine, row, col);
				break;
			}
			else//������
			{
				//ͳ�ƣ�x��y����Χ�ж�����
				int count=get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				displayBoard(show,row, col);
				win++;
			}
		}
		
		else {
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�������׳ɹ�\n");
		displayBoard(mine, ROW, COL);
	}
	

}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}