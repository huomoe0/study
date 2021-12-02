#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s1,s2,s3,max,ans;
    cin >> s1 >> s2 >> s3;
    max = s1+s2+s3;
    int a[100] = {0};
    for(int i = 1;i <= s1;i++)
    {
        for(int j = 1;j <= s2;j++)
        {
            for(int k = 1;k <= s3;k++)
            {
                a[i+j+k]++;
            }
        }
    }
    int t = a[3];
    for(int i = 4;i <= max;i++)
    {
        if(a[i] > t)
        {
            t = a[i];
            ans = i;
        }
    }
    printf("%d",ans);
    return 0;
}