#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0,l,i,j,cnt = 0;
    cin >> l;
    for(i = 2;sum <= l;i++)
    {
        for(j = 2;j <= sqrt(i);j++)
        {
            if(i % j == 0)  break;
        }
        if(j > sqrt(i))
        {
            if(sum + i > l) break;
            else sum += i;
            cnt++;
            cout << i << endl;
        }
    }
    cout << cnt;
    return 0;
}