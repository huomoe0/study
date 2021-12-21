#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef struct Node
//{
//	double data;
//	struct Node* next;
//}Node;
//
//void Print(Node* h)
//{
//	Node* p = h->next;
//	while (p != NULL)
//	{
//		printf("%.2f\n", p->data);
//		p = p->next;
//	}
//}
//void Create(Node*h)
//{
//	Node* p;
//	Node* tail = h;
//	double e;
//	while (scanf("%lf",&e) && e != 0)
//	{
//		p = (Node*)malloc(sizeof(Node));
//		p->next = NULL;
//		p->data = e;
//		tail->next = p;
//		tail = p;
//	}
//}
//
//void Del(Node* h, double a)
//{
//	Node* p = h;
//	while (p->next != NULL && p->next->data != a)
//	{
//		p = p->next;
//	}
//	if (p->next != NULL)
//	{
//		Node* t = p->next;
//		p->next = t->next;
//		free(t);
//	}
//}
//
//int main()
//{
//	Node* head = (Node*)malloc(sizeof(Node));
//	Create(head);
//	
//	double a = 2;
//	Del(head,a);
//	Print(head);
//	return 0;
//}

//int main()
//{
//	char s[55] = { 0 };
//	sprintf(s, "%s", "aaaaaaaaaa");
//	FILE* p = fopen("a.txt", "r");
//	fscanf(p, "%s", s);
//	printf("%s", s);
//	return 0;
//}

//#include <iostream>
//#include <cmath>
//using namespace std;
//bool judgePow2(int x)//判断x是不是2的k次方
//{
//    int y = log(x) / log(2);
//    int result = pow(2, y);
//    return result == x;
//}
//int add(int n, int k)
//{
//    if (n == 1) return 1;
//    if (n == 2) return k;
//    if (judgePow2(n) == 1)
//    {
//        int p = log(n) / log(2);
//        int result = pow(k, p);
//        return result;
//    }
//    int temp = log(n) / log(2);
//    int base = pow(k, temp);
//    int temp2 = pow(2, temp);
//    return base + add(n - temp2, k);
//}
//int main()
//{
//    int m, n;
//    cin >> m;
//    cin >> n;
//    cout << add(n, m) << endl;
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int n, i, t,a[11] = {0};
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d", &t);
//		while (t != 0)
//		{
//			a[t % 10]++;
//			t /= 10;
//		}
//	}
//	int max = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (a[i] > max)	max = a[i];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (max == a[i])	printf("%d ", i);
//	}
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int n, a[10][10] = { 0 };
//	scanf("%d", &n);
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (i > j && a[i][j]);	break;
//		}
//	}
//	if (i == n && j == n)	printf("YES");
//	else	printf("NO");
//	return 0;
//}


#include<stdio.h>  
int main(void)
{
	int n, value, value1, value2, sum = 0, x, value3, qian = 1000, y = 0, jishuqi = 0;
	scanf("%d", &n);
	value = n / 100000000;
	if (value != 0) 
	{
		printf("%cY", 'a' + value);                      /*输出亿位*/
	}
	value1 = n % 100000000;
	value2 = value1 / 10000;                                 /*得到万位数字*/
	while (qian != 0) 
	{                                            /*输出万位*/
		if (value2 == 0)
		{
			break;
		}
		x = value2 / qian;
		value2 = value2 % qian;
		qian = qian / 10;
		y++;
		if (value == 0 && x == 0) 
		{
			if (jishuqi != 1) 
			{
				continue;
			}
		}
		if (x == 0)
		{
			sum++;
			if (sum <= 1)
			{
				if (y != 4) 
				{
					printf("%c", 'a');
				}
			}
		}
		if (x != 0) 
		{
			sum = 0;
			jishuqi = 1;
			printf("%c", 'a' + x);
			switch (y) 
			{
			case 1: printf("Q"); break;
			case 2: printf("B"); break;
			case 3: printf("S"); break;
			}
		}
	}
	if (y != 0)
	{
		printf("W");                                      /*输出万位结束*/
	}
	sum = 0;                                                    /*输出千位以下需要重新赋初始值，因为在万位运算的时候值变化了*/
	qian = 1000;
	y = 0;
	jishuqi = 0;
	value3 = n % 10000;                                    /*得到千以及以下数字*/
	while (qian != 0) 
	{
		x = value3 / qian;
		value3 = value3 % qian;
		qian = qian / 10;
		y++;
		if ((n % 100000000) / 10000 == 0 && x == 0) 
		{
			if (jishuqi != 1)
			{
				continue;
			}
		}
		if (value3 != 0) 
		{
			if (x == 0)
			{
				sum++;
				if (sum <= 1) 
				{
					printf("%c", 'a');
				}
			}
		}
		if (x != 0)
		{
			sum = 0;
			jishuqi = 1;
			printf("%c", 'a' + x);
			switch (y) {
			case 1: printf("Q"); break;
			case 2: printf("B"); break;
			case 3: printf("S"); break;
			}
		}
	}
	if (n == 0) 
	{
		printf("%c", 'a');
	}
}