#include <stdio.h>
int main()
{
	double s,ans;
	scanf("%lf",&s);
	if(s < 1000)	ans = s;
	else if(s >= 1000 && s < 2000)	ans = s*0.9;
	else if(s >= 2000 && s < 3000)	ans = s*0.85;
	else if(s >= 3000 && s < 4000)	ans = s*0.8;
	else	ans = s*0.75;
	printf("%.2f",ans);
	return 0;
}
