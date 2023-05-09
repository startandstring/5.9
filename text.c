#pragma once
#include"game.h"


void menu()
{
	printf("***********************\n");
	printf("*****   1. play   *****\n");
	printf("*****   0. exit   *****\n");
	printf("***********************\n");
}
void game()
{
	char mine[ROWS][COLS];//��Ų����׵���Ϣ
	char show[ROWS][COLS];//����Ų�����׵���Ϣ
	//��ʼ������1.mine�����ʼȫΪ'0' 2.show�����ʼȫ'*'
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(mine, ROW, COL);
	//��������
	SetMine(mine, ROW, COL);
	//�Ų�����
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		case 3:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}