#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,ans = 0;
	scanf("%d",&n);
	for(i = 101;i <= n;i++)
	{
		int t = sqrt(i);
		if(t*t == i)
		{
			int cnt = 0;
			if(i / 100 == i/10%10)	cnt++;
			if(i / 100 == i % 10)	cnt++;
			if(i/10%10 == i % 10)	cnt++;
			if(cnt == 1)	ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
