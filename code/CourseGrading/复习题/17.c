#include <stdio.h>
int main()
{
	int n,i,j,m,a[30] = {0},b[15] = {0};
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i = 0;i < m;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i = 0;i < n;i++)
	{
		int flag = 0;
		for(j = 0;j < m;j++)
		{
			if(a[i] == b[j])
			{
				flag = 1;
				break;
			}
		}
		if(!flag)	printf("%d ",a[i]);
	}
	for(i = 0;i < m;i++)
	{
		int flag = 0;
		for(j = 0;j < n;j++)
		{
			if(b[i] == a[j])
			{
				flag = 1;
				break;
			}
		}
		if(!flag)	printf("%d ",b[i]);
	}
	return 0;
}
