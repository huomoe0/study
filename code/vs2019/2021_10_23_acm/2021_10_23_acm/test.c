#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int i, j, k;
	long int n;
	int len = 0;
	int arr[20] = { 0 };
	for (i = 0; i < t; i++)
	{
		len = 0;
		scanf("%ld", &n);
		for(k = 0;n > 0;k++)
		{
			arr[k] = n % 10;
			n /= 10;
		}
		len += k;
		for (j = 0; j < k - 1; j++)
		{
			if (arr[j] != 0)
				len++;
			if (arr[j] == 0 && arr[j + 1] == 0 && j <= 1)
				len--;
		}
		
		printf("%d\n", len);
	}
	return 0;
}



//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a[100000] = { 0 };
//	int i, j;
//	long long m;
//	int left = 0, right = n - 1, flag = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf(" %ld", &m);
//		a[i] = m;
//	}
//	for (left = 0; left <= right; left++)
//	{
//		flag = 0;
//		for (j = 0; j <= right; j++)
//		{
//			if (left == j)
//				continue;
//			if (a[left] == a[j])
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			printf("%d\n", a[left]);
//			return 0;
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i, j,k,m;
//	long long sum = 1;
//	int a[100] = { 0 };
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &m);
//		a[i] = m;
//	}
//	int l, r;
//	scanf("%d", &n);
//	for (k = 0; k < n; k++)
//	{
//		scanf(" %d %d", &l, &r);
//		for (j = l; j <= r; j++)
//		{
//			sum *= a[j - 1];
//		}
//		printf("%lld\n", sum);
//		sum = 1;
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char a[10000] = { 0 };
//	scanf("%s", a);
//	int i, count = 0;
//	for(i = 0;;i++)
//	{
//		if (a[i] == '¸ï' && a[i + 1] == 'Ãü')
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}