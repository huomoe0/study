#include <stdio.h>
int main()
{
	int n,i,j,a[15] = {0};
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0;i < n-1;i++)
	{
		int ind = i;
		for(j = i+1;j < n;j++)
		{
			if(a[j] > a[ind])	ind = j;
		}
		if(ind != i)
		{
			int t = a[ind];
			a[ind] = a[i];
			a[i] = t;
		}
	}
	for(i = 0;i < n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
