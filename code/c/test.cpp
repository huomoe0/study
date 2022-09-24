#include <stdio.h>
int main()
{
    float r, y, p;
    r = 0.0225;
    scanf("%f", &y);
    p = y * (1 + r);
    printf("p=%7.2f\n", p);
    return 0;
}