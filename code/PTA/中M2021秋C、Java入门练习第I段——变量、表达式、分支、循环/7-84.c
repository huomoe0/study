#include <stdio.h>
#include <math.h>
int main()
{
    int n,tmp;
    scanf("%d",&n);
    int first = 0, len = 0, maxm = sqrt(n)+1;
    for(int i = 2; i <= maxm; i++)
    {
        int j;
        tmp = 1;
        for(j = i; j <= maxm; j++)
        {
            tmp *= j;
            if(n%tmp != 0) break; //超出或当前数不为因数
        }
        if(j - i > len)
            len = j-i, first = i;
    }
    if(first == 0)    //素数或1
        printf("1\n%d",n);
    else
    {
        printf("%d\n%d",len,first);
        for(int i = 1; i < len; i++)
        {
            printf("*%d",first+i);
        }
    }
	return 0;
}