#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[30] = {0};
    char ch;
    while(~scanf("%c",&ch))
    {
		if(ch >= 'A' && ch <= 'Z')	a[ch-'A']++;
	}
	int max = a[0];
	for(int i = 1;i < 26;i++)
		if(a[i] > max)	max = a[i];
	for(int i = max-1;i >= 0;i--)
	{
		for(int j = 0;j < 26;j++)
		{
			if(a[j] > i)
			{
				if(j == 0)	printf("*");
				else	printf(" *");
			}
			else if(j == 0)	printf(" ");
			else	printf("  ");
		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
}
