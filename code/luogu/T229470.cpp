#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	string s,v = "chuanzhi";
	cin >> s;
	int res = 0,cnt = 0;
	while((res = (int)s.find(v,res)) != -1)
	{
		res++,cnt++;
	}
	cout << cnt;
	return 0;
}