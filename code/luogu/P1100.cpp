#include <bits/stdc++.h>
using namespace std;
long long Pow(int a,int b)
{
    long long i,v = 1;
    for(i = 0;i < b;i++)
    {
        v *= a;
    }
    return v;
}
int main()
{
    vector<int> num(32);
    int n,tmp,i,j = 15;
    long long re = 0;
    scanf("%d",&n);
    tmp = n;
    for(i = 31;i >= 0;i--)
    {
        num[i] = tmp % 2;
        tmp /= 2;
        if(i > 15 && num[i] == 1)
            re += Pow(2,47 - i);
        else if(i <= 15 && num[i] == 1)
            re += Pow(2,15-i);
    }
    printf("%lld",re);
    return 0;
}