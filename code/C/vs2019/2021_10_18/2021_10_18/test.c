#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char ch;
	ch = getchar();
	while (ch != '\n')
	{
		printf("%c\n", ch + 32);
		ch = getchar();
	}
	return 0;
}//