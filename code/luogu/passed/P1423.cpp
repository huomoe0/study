#include <bits/stdc++.h>
using namespace std;
int main()
{
    double aim,sum = 0,now = 2,cnt = 0;
    cin >> aim;
    while(sum < aim)
    {
        sum += now;
        cnt++;
        now *= 0.98;
    }
    cout << cnt;
    return 0;
}