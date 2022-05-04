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
				printf("■");
			}
			else if (i == 0 || i == ROW - 1)
			{
				face[i][j] = WALL;
				printf("■");
			}
			else face[i][j] = KONG;
		}
	}
	color(7);
	CursorJump(0, ROW);
	printf("当前得分:%d", grade);
	CursorJump(COL, ROW);
	printf("历史最高得分:%d", max);
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
	printf("●");
}

void DrawSnake(int flag)
{
	if (flag)
	{
		color(10);
		CursorJump(2 * snake.x, snake.y);
		printf("■");
		for (int i = 0; i < snake.len; i++)
		{
			CursorJump(2 * body[i].x, body[i].y);
			printf("□");
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
	int tmp = 0; //记录蛇的移动方向
	goto first; //第一次进入循环先向默认方向前进
	while (1)
	{
		n = _getch(); //读取键值
		//在执行前，需要对所读取的按键进行调整
		switch (n)
		{
		case UP:
		case DOWN: //如果敲击的是“上”或“下”
			if (tmp != LEFT && tmp != RIGHT) //并且上一次蛇的移动方向不是“左”或“右”
			{
				n = tmp; //那么下一次蛇的移动方向设置为上一次蛇的移动方向
			}
			break;
		case LEFT:
		case RIGHT: //如果敲击的是“左”或“右”
			if (tmp != UP && tmp != DOWN) //并且上一次蛇的移动方向不是“上”或“下”
			{
				n = tmp; //那么下一次蛇的移动方向设置为上一次蛇的移动方向
			}
		case SPACE:
		case ESC:
		case 'r':
		case 'R':
			break; //这四个无需调整
		default:
			n = tmp; //其他键无效，默认为上一次蛇移动的方向
			break;
		}
	first: //第一次进入循环先向默认方向前进
		switch (n)
		{
		case UP: //方向键：上
			run(0, -1); //向上移动（横坐标偏移为0，纵坐标偏移为-1）
			tmp = UP; //记录当前蛇的移动方向
			break;
		case DOWN: //方向键：下
			run(0, 1); //向下移动（横坐标偏移为0，纵坐标偏移为1）
			tmp = DOWN; //记录当前蛇的移动方向
			break;
		case LEFT: //方向键：左
			run(-1, 0); //向左移动（横坐标偏移为-1，纵坐标偏移为0）
			tmp = LEFT; //记录当前蛇的移动方向
			break;
		case RIGHT: //方向键：右
			run(1, 0); //向右移动（横坐标偏移为1，纵坐标偏移为0）
			tmp = RIGHT; //记录当前蛇的移动方向
			break;
		case SPACE: //暂停
			system("pause>nul"); //暂停后按任意键继续
			break;
		case ESC: //退出
			system("cls"); //清空屏幕
			color(7); //颜色设置为白色
			CursorJump(COL - 8, ROW / 2);
			printf("  游戏结束  ");
			CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		case 'r':
		case 'R': //重新开始
			system("cls"); //清空屏幕
			main(); //重新执行主函数
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
		printf("当前得分:%d", grade);
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