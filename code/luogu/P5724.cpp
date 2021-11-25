#include <bits/stdc++.h>
using namespace std;
int main()
{
    int min = 10000,max = -1,n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        if(t > max) max = t;
        if(t < min) min = t;
    }
    cout << max - min;
    return 0;
}