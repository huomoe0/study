#include <stdio.h>
struct book
{
	char name[30];
	double v;
}a[15];
int main()
{
	int n,id,i;
	double max = 0;
	scanf("%d",&n);
	getchar();
	for(i = 0;i < n;i++)
	{
		fgets(a[i].name,50,stdin);
		scanf("%lf",&a[i].v);
		getchar();
		if(a[i].v > max)
		{
			max = a[i].v;
			id = i;
		}
	}
	printf("%s",a[id].name);
	return 0;
}
