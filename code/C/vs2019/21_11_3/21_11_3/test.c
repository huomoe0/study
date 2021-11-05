#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
int main()
{
	char a[200];
	char b[100];
	scanf("%s", a);
	scanf("%s", b);
	strcat(a, b);
	int length = strlen(a);
	int i, k;
	for (i = 0; i < length - 1; i++)
	{
		for (k = 0; k < length; k++)
		{
			if (k > 0 && a[k - 1] > a[k])
			{
				char temp = a[k];
				a[k] = a[k - 1];
				a[k - 1] = temp;
			}
		}
	}
	printf("%s", a);
	return 0;
}