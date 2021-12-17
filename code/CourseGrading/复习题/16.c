#include <stdio.h>
int main()
{
	int n,i;
	double min = 10000000,t,sum = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%lf",&t);
		if(t < min)	min = t;
		sum += t;
	}
	if(sum < 20)	printf("error");
	else if(sum >= 20 && sum < 30)	printf("%.2f",sum+8);
	else if(sum >= 30 && sum < 40)	printf("%.2f",sum+5);
	else if(sum >= 40 && sum < 80)	printf("%.2f",sum);
	else	printf("%.2f",sum-min);
	return 0;
}
