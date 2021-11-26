#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
struct a
{
    char x;
    char b;
    //char c;
    //char d;
    int y;
    double z;
};
union aa
{
    char x;
    char b;
    char c;
    int n;
    char d[20];
};
int main()
{
    
    printf("%d\n",sizeof(struct a));
    printf("%d\n",sizeof(union aa));
    return 0;
}