#include <bits/stdc++.h>
int num(int n)
{
    switch(n)
    {
        case 0:return 6;
        case 1:return 2;
        case 2:return 5;
        case 3:return 5;
        case 4:return 4;
        case 5:return 5;
        case 6:return 6;
        case 7:return 3;
        case 8:return 7;
        case 9:return 6;
        default:return 0;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,tmp = 0,s = 4,count = 0;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= n;j++)
        {
            int a = i,b = j,c = i+j;
            do
            {
                tmp += num(a%10);
                a /= 10;
            }while(a > 0);
            do
            {
                tmp += num(b%10);
                b /= 10;
            }while(b > 0);
            do
            {
                tmp += num(c%10);
                c /= 10;
            }while(c > 0);
            if(tmp + s == n)
                //printf("%d+%d=%d\n",i,j,i+j);
                count++;
            tmp = 0;
        }
    }
    printf("%d\n",count);
    return 0;
}