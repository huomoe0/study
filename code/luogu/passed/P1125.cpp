#include <bits/stdc++.h>
using namespace std;
int maxn = -1,minn = 20000000,a[30];
int main()
{
    string s;
    cin >> s;
    for(char i = 'a';i <= 'z';i++)
    {
        int t = count(s.begin(),s.end(),i);
        if(t != 0)  maxn = max(maxn,t),minn = min(minn,t);
    }
    int c = maxn - minn,i;
    if(c >= 2)
    {
        for(i = 2;i <= sqrt(c);i++)
        {
            if(c % i == 0)  break;
        }
        if(i > sqrt(c)) printf("Lucky Word\n"),cout << c;
    }
    else    printf("No Answer\n0");
    return 0;
}