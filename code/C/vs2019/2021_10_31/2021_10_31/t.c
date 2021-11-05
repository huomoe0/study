#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	char ch;
	while (~scanf("%c", &ch))
	{
		if (ch == 'B')
			printf("-");
		else if (ch == 'A')
			printf(".");
		else

			printf("%c", ch);

	}
}