#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wage
{
	long long id;
	char name[20];
	double base,up,down,bonus;
}wage;

typedef struct Node
{
	wage data;
	struct Node* next;
}Node, * LinkList;

enum choice
{
	EXIT, ADD, DELETE, SEARCH, CHANGE,PRINT
};


void menu();

void load(LinkList);

void print(LinkList);

void add(LinkList);

void save(LinkList);

//void search(LinkList);

void change(LinkList);