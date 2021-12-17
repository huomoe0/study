#include <stdio.h>
typedef struct cpx
{
	int a,b;
}cpx;
int main()
{
	cpx x,y,ans;
	scanf("%d %d %d %d",&x.a,&x.b,&y.a,&y.b);
	ans.a = x.a*y.a - x.b*y.b;
	ans.b = x.a*y.b + x.b*y.a;
	printf("%d%+di",ans.a,ans.b);
	return 0;
}
