#include <stdio.h>
int gcd(int a,int b)
{
	int r = a % b;
	while(r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",gcd(a,b));
	return 0;
}
