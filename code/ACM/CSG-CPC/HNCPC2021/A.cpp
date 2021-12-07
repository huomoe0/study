#include <bits/stdc++.h>
using namespace std;
struct s
{
	char id;
	int js,jq,jf;
};
int main()
{
    int t;
    cin >> t;
    map<char,s> mp;
    for(int i = 0;i < t;i++)
    {
    	for(char n = 'A';n <= 'F';n++)
		{
			mp[n].js = 0;
			mp[n].jf = 0;
			mp[n].jq = 0;
			
		}
		for(int j = 0;j < 15;j++)
		{
			char x,y;
			int a,b;
			cin >> x >> y;
			for(int k = 0;k < 2;k++)
			{
				cin	>> a >> b;
				mp[x].jq += a;
				mp[y].jq += b;
				mp[x].js += (a-b);
				mp[y].js += (b-a);
				if(a > b)	mp[x].jf += 3;
				else	if(a < b)	mp[y].jf += 3;
				else
				{
					mp[x].jf += 1;
					mp[y].jf += 1;
				}
			}
		}
		for(char m = 'A';m <= 'F';m++)
		{
			printf("%d %d %d\n",mp[m].jf,mp[m].js,mp[m].jq);
		}
	}
	
	return 0;
}
