#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student
{
	int num;
	char name[20];
	int score;
	struct student* next;
}stu;

void menu();

struct student* Create();

struct student* Insert(struct student* newNode, struct student* head);

void Delete(struct student* head, int num);

void Print(struct student* head);
