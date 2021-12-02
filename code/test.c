#include <stdio.h>

int getCount(int);

int main()
{
    int n = 0,i = 0,a[10000],ans = 0,cnt = 0;
    do
	{
		int t;
		scanf("%d",&t);
		if(t == -1)	break;
		a[n++] = t;
	}while(1);
    for(i = 0;i < n;i++)
    {
		if(getCount(a[i]) > cnt)
		{
			ans = a[i];
			cnt = getCount(a[i]);
		}
		else if(getCount(a[i]) == cnt)	ans = a[i];
	}
	printf("%d %d\n",ans,cnt);
    return 0;
}

int getCount(int n)
{
	int cnt = 0,i;
	for(i = 1;i <= n;i++)
	{
		if(n % i == 0)	cnt++;
	}
	return cnt;
}
