#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;// 返回-1 a在b前     返回1 a在b后
	//return *(int*)b - *(int*)a;   //降序排列
}
void Swap(char* p, char* q, int wid)
{
	for (int i = 0; i < wid; i++)
	{
		char t = *p;
		*p = *q;
		*q = t;
		p++;
		q++;
	}
}
void bubble_sort(void* base, size_t n, size_t size, int (*cmp)(const void*, const void*))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
		}
	}
}
int main()
{
	int arr[] = { 23,11,55,11,22,55,0,2 };
	//for (int i = 0; i < 4; i++) // 冒泡排序 n-1次
	//{
	//	for (int j = 0; j < 4 - i; j++)//每次交换n-1-i次
	//	{
	//		int t = a[j];
	//		a[j] = a[j + 1];
	//		a[j + 1] = t;
	//	}
	//}

	//qsort(arr, 5, sizeof(arr[0]), cmp);
	bubble_sort(arr, 5, sizeof(arr[0]), cmp);
	int l = strlen('a');
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d",l);
	return 0;
}