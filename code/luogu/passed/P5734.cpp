#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string str,s;
    cin >> n >> str;
    while(n--)
    {
		int a;
		cin >> a;
		if(a == 1)
		{
			cin >> s;
			str += s;
			cout << str << endl;
		}
		else if(a == 2)
		{
			int x,y;
			cin >> x >> y;
			str = str.substr(x,y);
			cout << str << endl;
		}
		else if(a == 3)
		{
			int x;
			cin >> x >> s;
			str = str.insert(x,s);
			cout << str << endl;
		}
		else if(a == 4)
		{
			cin >> s;
			cout << (int)str.find(s) << endl;
		}
	}
	return 0;
}
