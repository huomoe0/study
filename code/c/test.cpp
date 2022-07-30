#include <cstdio>
#include <iostream>
int test(int a,int b = 0,int c = 0)
{
    printf("a = %d b = %d c = %d",a,b,c);
    return 0;
}

int main()
{
    test(1,,1);
    return 0;
}