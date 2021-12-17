#include <stdio.h>
#include <string.h>
int main()
{
	int n,letter = 0,blank = 0,digit = 0,other = 0;
	scanf("%d",&n);
	while(n--)
	{
		char ch = getchar();
		if(ch >= '0' && ch <= '9')	digit++;
		else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))	letter++;
		else if(ch == ' ' || ch == '\n')	blank++;
		else	other++;
	}
	printf("%d %d %d %d",letter,blank,digit,other);
	return 0;
}
