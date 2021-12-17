#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int sum = 0,i,j,a[55] = {0};
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	for(i = 0;i < n-1;i++)
	{
		int cnt = 0;
		for(j = 0;j < n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				cnt++;
			}
		}
		if(!cnt)	break;
	}
	printf("%.2f",(sum-a[0]-a[1]-a[n-1]-a[n-2])/(n-4.0));
	return 0;
}
