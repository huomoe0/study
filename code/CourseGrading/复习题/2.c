#include <stdio.h>
#include <string.h>
int main()
{
	char a[6][50];
	int i,j;
	for(i = 0;i < 5;i++)
	{
		scanf("%s",a[i]);
	}
	for(i = 0;i < 4;i++)
	{
		for(j = 0;j < 4-i;j++)
		{
			if(strcmp(a[j],a[j+1]) > 0)
			{
				char t[50];
				strcpy(t,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],t);
			}
		}
	}
	for(i = 0;i < 5;i++)
	{
		printf("%s\n",a[i]);
	}
	return 0;
}
