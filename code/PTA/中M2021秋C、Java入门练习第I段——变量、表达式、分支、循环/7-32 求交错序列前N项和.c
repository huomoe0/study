#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d",&n);
    int i = 0;
    double sum = 0;
    double flag = 1.0;
    int a = 1;
    int b = 1;
    for(i = 1;i <= n;i++)
    {
        sum += flag * (a * 1.0 / b);
        a += 1;
        b += 2;
        flag = -flag;
    }
    printf("%.3lf",sum);
    return 0;
}