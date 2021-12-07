#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,r,c,v;
    while(cin >> n >> m)
    {
		cin >> r >> c >> v;
		if(v < r*c)	printf("No\n");
		else	printf("Yes\n");
	}
	return 0;
}
