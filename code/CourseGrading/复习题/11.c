#include <stdio.h>
int main()
{
	int n,max = -20000000,min = 200000000;
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		if(t > max)	max = t;
		if(t < min)	min = t;
	}
	printf("%d %d",max,min);
	return 0;
}
