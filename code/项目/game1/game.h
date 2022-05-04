#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 22
#define COL 45

#define KONG 0
#define WALL 1
#define FOOD 2
#define HEAD 3
#define BODY 4

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27

struct Snake
{
	int len, x, y;
}snake;
struct Body
{
	int x, y;
};

void CursorJump(int x, int y);
void HideCursor();
void color(int c);
void InitInterface();
void InitSnack();
void RandFood();
void DrawSnake(int flag);
void MoveSnake(int x, int y);
void Game();
void run(int x, int y);
void JudgeFunc(int x, int y);


