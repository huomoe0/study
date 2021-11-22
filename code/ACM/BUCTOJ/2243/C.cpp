#include <bits/stdc++.h>
using namespace std;
int a[200005] = {0};
int main()
{
    int n,i,max1 = 0,max2 = 0;
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] > max1)
        {
            max1 = a[i];
        }
        else if(a[i] <= max1 && a[i] > max2)
            max2 = a[i];
    }
    for(int j = 1;j <= n;j++)
    {
        if(a[j] == max1)    cout << max2 << endl;
        else    cout << max1 << endl;
    }
    return 0;
}