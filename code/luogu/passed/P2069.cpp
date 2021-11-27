#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,m,height,j,k;
    cin >> n >> m;
    int s[n+1] = {0};
    for(i = 1;i <= n;i++)
    {
        s[i] = i;
    }

    for(i=1,height=1;i<=m;i++)//次数
	{
		int jump=i*i*i%5+1;//跳的距离 
		height+=jump;//当前高度+跳的距离 
		if(height>n-i+1)
            height=jump+1;//重新跳
		if(i!=m)
		{
			for(j=height+1;j<=n-i+1;j++)//果子下落
			{
				s[j-1]=s[j];
			}
		}
	}
    cout << s[height];
    return 0;
}