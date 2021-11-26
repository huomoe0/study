#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,i,flag = 0; //flag表示前面是否输出过
    scanf("%d",&n);
    for(i = n;i >= 0;i--)
    {
        scanf("%d",&a);
        if(a == 0)  continue;

        if(a < 0)   printf("-");  //符号
        else if(flag == 1 && a > 0)     printf("+");

        int b = abs(a);
        if(i > 1) //数
        {
            if(b == 1)     printf("x^%d",i);
            else printf("%dx^%d",b,i);
            flag = 1;
        }
        else if(i == 1)
        {
            if(b == 1)     printf("x");
            else    printf("%dx",b);
            flag = 1;
        }
        else if(i == 0)
        {
            printf("%d",b);
        }
    }
    return 0;
}