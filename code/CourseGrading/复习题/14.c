#include <stdio.h>
#include <string.h>
int main()
{
	char ch,a[50] = {0};
	fgets(a,50,stdin);
	ch = getchar();
	int i;
	for(i = 0;i < strlen(a);i++)
	{
		if(a[i] == ch)	continue;
		else	printf("%c",a[i]);
	}
	return 0;
}
