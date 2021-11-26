#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pass;
    int n,i;
    cin >> n >> pass;
    n %= 26;
    for(i = 0;i < pass.size();i++)
    {
        if(pass[i] + n <= 'z')
        {
            pass[i] += n;
        }
        else
        {
            pass[i] = pass[i] - 26 + n;
        }
    }
    cout << pass;
    return 0;
}