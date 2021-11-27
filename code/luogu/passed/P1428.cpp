#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[102] = {0};
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        cnt = 0;
        for(int j = 0;j < i;j++)
        {
            if(a[j] < a[i]) cnt++;
        }
        printf("%d ",cnt);
    }
    return 0;
}