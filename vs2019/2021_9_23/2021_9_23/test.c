//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//
//	//int i = 0;
//	//int a = 0;
//	//int sum = 1;
//	//int max = 0;
//	//scanf("%d", &a);
//	//for (i = 1; i <= a; i++)
//	//{
//	//	sum = sum * i;
//	//	max += sum;
//	//}
//	//printf("%d", max);
//	//return 0;
//
//	char arr[] = "1";
//	printf("%d", sizeof(arr));
//	return 0;
//
//}





#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d ", i);
		}
	}

	return 0;
}