#include <bits/stdc++.h>
using namespace std;
int mj(int h[],int max)
{
    int i,j,l = 0,r;
    for(i = max - 1;i > 0;i++)
    {
        if(l < h[i])
            l = i;
    }
}
int main()
{
    int n,i,j,area,max = 0;
    cin >> n;
    int h[10000] = {0};
    for(i = 0;i < n;i++)
    {
        cin >> h[i];
        if(h[i] > max)
            max = i;
    }
    area = mj(h,max);
    cout << area;
}