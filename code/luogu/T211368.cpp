#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag[101] = {0};
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        if(flag[t] == 0)
        {
            printf("%d ",t);
            flag[t]++;
        }
    }
    return 0;
}