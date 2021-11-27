#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    bool a1 = x % 2 == 0;
    bool a2 = x > 4 && x <= 12;
    if(a1 && a2)    printf("1 ");
    else    printf("0 ");
    if(a1 || a2)    printf("1 ");
    else    printf("0 ");
    if((a1 && !a2) || (!a1 && a2))    printf("1 ");
    else    printf("0 ");
    if(!(a1 || a2))    printf("1");
    else    printf("0");
    return 0;
}