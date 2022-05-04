#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "game.h"
#pragma warning (disable:4996)
int grade, max;
int main()
{
	HideCursor();
	int n = -1;
	srand((unsigned)time(NULL));
	do
	{
		printf("*************\n 1. 开始游戏\n 2.退出\n*************\n");
		while (n = getchar())
			if (n == '0' || n == '1')	break;
		if (n == '1')
		{
			system("cls");
			InitInterface();
			InitSnack();
			RandFood();
			DrawSnake(1);
			Game();
		}
	} while (n != '0');
	
	return 0;
}