#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    string s;
    cin >> a[0] >> a[1] >> a[2] >> s;
    sort(a,a+3);
    for(int i = 0;i < 3;i++)
    {
        switch(s[i])
        {
            case 'A':cout << a[0];break;
            case 'B':cout << a[1];break;
            case 'C':cout << a[2];break;
        }
        if(i < 2)   cout << ' ';
    }
    return 0;
}