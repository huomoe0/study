#include <stdio.h>
#include <string.h>
int main()
{
	char a[100] = {0},s[100] = {0};
	gets(a);
	gets(s);
	int i,j,len = strlen(a),lens = strlen(s);
	for(i = 0;i <= len-lens;i++)
	{
		if(a[i] == s[0])
		{
			for(j = 0;j < lens;j++)
			{
				if(a[i+j] != s[j])	break;
			}
			if(j == lens)
			{
				for(j = 0;j <= len-lens-i;j++)
				{
					a[i+j] = a[i+lens+j];
				}
				len = strlen(a);
				i--;
			}
		}
	}
	printf("%s",a);
	return 0;
}
