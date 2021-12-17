#include <stdio.h>
int main()
{
	int n,t = 0;
	scanf("%d",&n);
	if(n < 100 || n > 999)
	{
		printf("-1");
		return 0;
	}
	while(n)
	{
		t = t * 10 + n % 10;
		n /= 10;
	}
	printf("%d",t);
	return 0;
}
