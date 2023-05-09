#pragma once
#include"game.h"

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i=0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}

}
//��ӡ����
//��ӡ����������Ҫ���۵Ļ��������ÿո񣨼������һ�񣩣����������Σ�
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("--------ɨ����Ϸ--------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//��������
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//����10����
    //������������꣬������
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

//�����Χ�м�����
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] +
		mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}
//�Ų�����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while(win < row* col - EASY_COUNT)
	{
		printf("������Ҫ�������꣺>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź���������\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				//��λ�ò����ף���ͳ���������ĸ����м�����
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}