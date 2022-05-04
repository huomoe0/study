#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "game.h"

struct Body body[ROW * COL];
int face[ROW][COL];

extern int grade, max;

void HideCursor()
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = 0;
	curinfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

void CursorJump(int x,int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void InitInterface()
{
	color(6);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL;
				CursorJump(2 * j, i);
				printf("��");
			}
			else if (i == 0 || i == ROW - 1)
			{
				face[i][j] = WALL;
				printf("��");
			}
			else face[i][j] = KONG;
		}
	}
	color(7);
	CursorJump(0, ROW);
	printf("��ǰ�÷�:%d", grade);
	CursorJump(COL, ROW);
	printf("��ʷ��ߵ÷�:%d", max);
}

void InitSnack()
{
	snake.len = 2;
	snake.x = COL / 2;
	snake.y = ROW / 2;
	body[0].x = COL / 2 - 1;
	body[0].y = ROW / 2;
	body[1].x = COL / 2 - 2;
	body[1].y = ROW / 2;
	face[snake.y][snake.x] = HEAD;
	face[body[0].y][body[0].x] = BODY;
	face[body[1].y][body[1].x] = BODY;
}

void RandFood()
{
	int i, j;
	
	do
	{
		i = rand() % ROW, j = rand() % COL;
	} while (face[i][j] != KONG);
	face[i][j] = FOOD;
	color(12);
	CursorJump(2 * j, i);
	printf("��");
}

void DrawSnake(int flag)
{
	if (flag)
	{
		color(10);
		CursorJump(2 * snake.x, snake.y);
		printf("��");
		for (int i = 0; i < snake.len; i++)
		{
			CursorJump(2 * body[i].x, body[i].y);
			printf("��");
		}
	}
	else
	{
		if (body[snake.len - 1].x != 0)
		{
			CursorJump(2 * body[snake.len - 1].x, body[snake.len - 1].y);
			printf("  ");
		}
	}
}

void MoveSnake(int x, int y)
{
	DrawSnake(0);
	face[body[snake.len - 1].y][body[snake.len - 1].x] = KONG;
	face[snake.y][snake.x] = BODY;
	for (int i = snake.len - 1; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	body[0].x = snake.x, body[0].y = snake.y;
	snake.x += x,snake.y += y;
	DrawSnake(1);
}

void Game()
{
	int n = RIGHT;
	int tmp = 0; //��¼�ߵ��ƶ�����
	goto first; //��һ�ν���ѭ������Ĭ�Ϸ���ǰ��
	while (1)
	{
		n = _getch(); //��ȡ��ֵ
		//��ִ��ǰ����Ҫ������ȡ�İ������е���
		switch (n)
		{
		case UP:
		case DOWN: //����û����ǡ��ϡ����¡�
			if (tmp != LEFT && tmp != RIGHT) //������һ���ߵ��ƶ������ǡ��󡱻��ҡ�
			{
				n = tmp; //��ô��һ���ߵ��ƶ���������Ϊ��һ���ߵ��ƶ�����
			}
			break;
		case LEFT:
		case RIGHT: //����û����ǡ��󡱻��ҡ�
			if (tmp != UP && tmp != DOWN) //������һ���ߵ��ƶ������ǡ��ϡ����¡�
			{
				n = tmp; //��ô��һ���ߵ��ƶ���������Ϊ��һ���ߵ��ƶ�����
			}
		case SPACE:
		case ESC:
		case 'r':
		case 'R':
			break; //���ĸ��������
		default:
			n = tmp; //��������Ч��Ĭ��Ϊ��һ�����ƶ��ķ���
			break;
		}
	first: //��һ�ν���ѭ������Ĭ�Ϸ���ǰ��
		switch (n)
		{
		case UP: //���������
			run(0, -1); //�����ƶ���������ƫ��Ϊ0��������ƫ��Ϊ-1��
			tmp = UP; //��¼��ǰ�ߵ��ƶ�����
			break;
		case DOWN: //���������
			run(0, 1); //�����ƶ���������ƫ��Ϊ0��������ƫ��Ϊ1��
			tmp = DOWN; //��¼��ǰ�ߵ��ƶ�����
			break;
		case LEFT: //���������
			run(-1, 0); //�����ƶ���������ƫ��Ϊ-1��������ƫ��Ϊ0��
			tmp = LEFT; //��¼��ǰ�ߵ��ƶ�����
			break;
		case RIGHT: //���������
			run(1, 0); //�����ƶ���������ƫ��Ϊ1��������ƫ��Ϊ0��
			tmp = RIGHT; //��¼��ǰ�ߵ��ƶ�����
			break;
		case SPACE: //��ͣ
			system("pause>nul"); //��ͣ�����������
			break;
		case ESC: //�˳�
			system("cls"); //�����Ļ
			color(7); //��ɫ����Ϊ��ɫ
			CursorJump(COL - 8, ROW / 2);
			printf("  ��Ϸ����  ");
			CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		case 'r':
		case 'R': //���¿�ʼ
			system("cls"); //�����Ļ
			main(); //����ִ��������
		}
	}
}

void run(int x, int y)
{
	int t = 0;
	while (1)
	{
		if(t == 0)	t = 3000;
		while (--t)
		{
			if (_kbhit() != 0)	break;
		}
		if (t == 0)
		{
			JudgeFunc(x, y);
			MoveSnake(x, y);
		}
		else break;
	}
}

void JudgeFunc(int x, int y)
{
	if (face[snake.y + y][snake.x + x] == FOOD)
	{
		snake.len++;
		grade++;
		color(7);
		CursorJump(0, ROW);
		printf("��ǰ�÷�:%d", grade);
		RandFood();
	}
	else if (face[snake.y + y][snake.x + x] == WALL || face[snake.y + y][snake.x + x] == BODY)
	{
		Sleep(1000);
		system("cls");
		color(7);
		max = grade > max ? grade : max;
		CursorJump(2 * (COL / 3), ROW / 2);
		printf("Game Over");
	}
}