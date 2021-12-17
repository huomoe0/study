#include <stdio.h>
#include <math.h>
int main()
{
	int n = 0;
	double e,sum = 1,a = 0,b = -1,ret = 0;
	scanf("%lf",&e);
	do
	{
		ret = sum;
		a += 2;
		b += 2;
		sum *= (a / b) * (a / (b+2));
		n++;
	}while(2*fabs(sum-ret) >= e);
	printf("%d",n);
	return 0;
}
