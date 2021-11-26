#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin >> n >> q;
    map<string,string> s;
    string tm,da;
    for(int i = 0;i < n;i++)
    {
        cin >> tm >> da;
        s[tm] = da;
    }
    int count = 0;
    for(int i = 0;i < q;i++)
    {
        cin >> tm;
        for(int j = 0;j < 4;j++)
        {
            cin >> da;
            if(da == s[tm])
            {
                printf("%c\n",'A'+j);
            }
        }
    }
    return 0;
}
    