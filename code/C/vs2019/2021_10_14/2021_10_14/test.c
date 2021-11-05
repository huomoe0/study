#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
int minf(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}
int maxf(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a1, b1, a2, b2;
    int sign = 0;
    scanf("%d/%d", &a1, &b1);
    for (int i = 1; i <= n; i++)
    {
        if (i <= n - 1)
            scanf("%d/%d", &a2, &b2);
        else
            break;
        if (a2 < 0)
        {
            sign = 1;
            a2 = labs(a2);
        }
        for (int j = maxf(b1, b2); j <= b1 * b2; j++)
        {
            if (j % b1 == 0 && j % b2 == 0)
            {
                if (sign == 1)
                {
                    a2 = -a2;
                    sign = 0;
                }
                if (minf(b1, b2) == b1)
                    a1 = a1 * (j / b1) + a2 * (j / b2);
                else
                    a1 = a2 * (j / b2) + a1 * (j / b1);
                b1 = j;
                break;
            }
        }
        for (int k = 2; k < minf(a1, b1); k++)
        {
            if (a1 % k == 0 && b1 % k == 0)
            {
                a1 /= k;
                b1 /= k;
                k = 1;
            }
        }
    }
    /*if ((a1 < 0 && b1 > 0) || (a1 > 0 && b1 < 0))
    {
        a1 = labs(a1);
        b1 = labs(b1);
        putchar('-');
    }*/
    int zhengshu = a1 / b1;
    a1 %= b1;
    if (zhengshu != 0 && a1 != 0)
        printf("%d %d/%d", zhengshu, a1, b1);
    if (zhengshu == 0)
        printf("%d/%d", a1, b1);
    if (a1 == 0)
        printf("%d", zhengshu);
    return 0;
}