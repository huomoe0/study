#include <stdio.h>
int main()
{
	int i,j,k,m = 100;
	for(i = 0;i <= 20;i++)
	{
		for(j = 0;j <= 33;j++)
		{
			k = 3*(m-5*i-j*3);
			if(k >= 0 && i + j + k == 100 )	printf("x = %d, y = %d, z = %d\n",i,j,k);
		}
	}
	return 0;
}
