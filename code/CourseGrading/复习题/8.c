#include <stdio.h>
int main()
{
	int a[100] = {0},i,j,n;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(i = 0;i < n-1;i++)
	{
		int cnt = 0;
		for(j = 0;j < n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				cnt++;
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
		if(!cnt)	break;
	}
	for(i = 0;i < n;i++)
		printf("%d ",a[i]);
	return 0;
}
