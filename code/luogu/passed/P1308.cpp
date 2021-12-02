#include <bits/stdc++.h>
using namespace std;
int main()
{
    string dest,s;
    cin >> dest;
    dest = ' ' + dest + ' ';
    getchar();
    getline(cin,s);
    s = ' ' + s + ' ';
    int t = 0,cnt = 0,ind = 0,first = 1;
    for(int i = 1;i < s.size();i++)
    {
		if(s[i] <= 'Z' && s[i] >= 'A')
			s[i] += ('a' - 'A');
	}
	for(int i = 1;i < dest.size();i++)
	    {
			if(dest[i] <= 'Z' && dest[i] >= 'A')
				dest[i] += ('a' - 'A');
		}
    while(1)
    {
		t = (int)s.find(dest,t);
		if(t != -1)
		{
			cnt++;
			if(first)
			{
				first = 0;
				ind = t;
			}
		}
		else if(t == -1)	break;
		t+= 2;
	}
	if(first == 1)
	{
		printf("-1");
	}
	else printf("%d %d",cnt,ind);
	return 0;
}
