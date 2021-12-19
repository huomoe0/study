#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
		int x,cnt = 0;
		cin >> x;
		for(int i = 0;i < x;i++)
		{
			int t = x^i,j;
			if(t % 2 == 0 && t != 2)	continue;
			for(j = 2;j*j <= t;j++)
			{
				if(t % j == 0)
				{
					break;
				}
			}
			if(j*j > t)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
