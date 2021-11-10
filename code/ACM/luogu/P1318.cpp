#include <bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    if(a > b)
    return b;
    else return a;
}
int main()
{
    int n,i,j,area = 0,sum = 0,h = 0,flag = 0;
    cin >> n;
    int arr[10000] = {0};
    for(i = 0;i < n;i++)
    {
        cin >> arr[i];
    }
    for(i = 1;i < n-1;i++)
    {
        if(arr[i-1] > arr[i])
        {
            h = arr[i-1];
            flag = 1;
        }
        if(flag)
        {
            sum += h - arr[i];
        }
        else sum = 0;
        if(arr[i+1] >= h)
        {
            area += sum;
            flag = 0;
        }
    }
    cout << area;
}