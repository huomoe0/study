#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 0;
    int b = 0;
    int i = 0;
    for (i = 10; i <= n; i *= 10)
    {
        if (n / i < 9)
        {
            a = sizeof(i) - 1;
            break;
        }
    }
    b += n / (10 ^ i - 1);
    b += n % 10;
    printf("%d %d", a, b);
    return 0;
}