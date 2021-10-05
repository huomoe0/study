#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int x = 0;
    scanf("%d", &x);
    int s = 0;
    double t = 1;
    int i = 0;
    for(i = 1;;i++)
    {
        if ((int)t % x == 0)
        {
            s = t / x;
            break;
        }
        t = t * 10 + 1;

    }
    printf("%d %d", s, i);
    return 0;
}