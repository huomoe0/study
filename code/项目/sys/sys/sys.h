#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define ID_LEN 20
#define NAME_LEN 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wage
{
	char id[ID_LEN];
	char name[NAME_LEN];
	double base,up,down;
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

void search(LinkList);

void change(LinkList);

void del(LinkList);