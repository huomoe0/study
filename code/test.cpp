#include <bits/stdc++.h>
using namespace std;
int Ceil(const double a)
{
    if((int)a == a) return a;
    else return (int)(a+1);
}
int main()
{
    int (*p)(const double) = &Ceil;
    printf("%p\n",*p);
    printf("%p\n",Ceil);
    return 0;
}
