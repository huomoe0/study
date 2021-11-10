#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char a[10] = { 0 };
    scanf("%s", a);
    int count = 0;
    while (a[count] != 0)
        count++;
}