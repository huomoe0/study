#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h[15] = {0},max,count = 0;
    for(int i = 0;i < 10;i++)
    {
        cin >> h[i];
    }
    cin >> max;
    max += 30;
    for(int i = 0;i < 10;i++)
    {
        if(max >= h[i])
            count++;
    }
    cout << count;
    return 0;
}