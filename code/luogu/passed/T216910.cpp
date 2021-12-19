#include <bits/stdc++.h>
using namespace std;
struct s
{
	int n;
	int a[2000];
};
int main()
{
    int n,k;
    cin >> n >> k;
    map<int,s> mp;
    while(n--)
    {
		int c;
		cin >> c;
		if(c == 1)
		{
			int p;
			cin >> p;
			for(int i = 0;i < p;i++)
			{
				int x,y;
				cin >> x >> y;
				mp[x].a[mp[x].n++] = y;
			}
		}
		if(c == 2)
		{
			int x,min,max,cnt = 0;
			cin >> x >> min >> max;
			for(int i = 0;i < mp[x].n;i++)
			{
				if(mp[x].a[i] <= max && mp[x].a[i] >= min)	cnt++;
			}
			cout << cnt << endl;
		}
    }
	return 0;
}
