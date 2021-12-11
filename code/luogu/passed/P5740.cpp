#include <bits/stdc++.h>
using namespace std;
struct stu
{
	string name;
	int all,a,b,c;
}s[1005];
int main()
{
    int n;
    cin >> n;
    int ind = 0,max = 0;
    for(int i = 0;i < n;i++)
    {
		cin >> s[i].name >> s[i].a >> s[i].b >> s[i].c;
		s[i].all = (s[i].a + s[i].b + s[i].c);
		if(s[i].all > max)	max = s[i].all;
	}
	for(int i = 0;i < n;i++)
	{
		if(s[i].all == max)
		{
			ind = i;
			break;
		}
	}
	cout << s[ind].name;
	printf(" %d %d %d",s[ind].a,s[ind].b,s[ind].c);
	return 0;
}
