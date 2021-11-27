#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,area = 0,max = -1,l,r;
    cin >> n;
    int h[10000] = {0};
    for(i = 0;i < n;i++)
    {
        cin >> h[i];
        if(h[i] > max)
            max = h[i];
    }
    //左右找最高
    for(i = 0;i < n;i++)
    {
        if(h[i] == max)
        {
            l = i;
            break;
        }
    }
    for(i = n-1;i >= 0;i--)
    {
        if(h[i] == max)
        {
            r = i;
            break;
        }
    }

    for(i = 1;i < l;i++)
    {
        if(h[i-1] > h[i])
        {
            int h1 = h[i-1];
            while(h[i] < h1)
            {
                area += h1 - h[i];
                i++;
            }
        }
    }
    for(i = l + 1;i < r;i++)
    {
        area += max - h[i];
    }
    for(i = n-1;i > r;i--)
    {
        if(h[i] > h[i-1])
        {
            int h1 = h[i];
            while(h[i-1] < h1)
            {
                area += h1 - h[i-1];
                i--;
            }
        }
    }
    cout << area;
    return 0;
}