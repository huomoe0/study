#include <bits/stdc++.h>
using namespace std;
int main()
{
    int min = 10000,n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        if(t < min) min = t;
    }
    cout << min;
    return 0;
}