#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
		int a,p;
		cin >> a >> p;
		if(p < 16)	a -= 10;
		else if(p > 20)	a -= (p-20);
		if(a < 0)	a = 0;
		cout << a << endl;
	}
	return 0;
}
