#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,cnt = 0,a[1000] = {0};
    cin >> x >> y;
    for(int i = x;i <= y;i++)
    {
		if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		{
			a[cnt++] = i;
		}
	}
	printf("%d\n",cnt);
	for(int i = 0;i < cnt;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
