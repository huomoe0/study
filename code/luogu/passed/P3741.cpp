#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len,cnt = 0,a[200] = {0},t = 0;
    string s;
    cin >> len >> s;
    for(int i = 0;i < len;i++)
    {
		t = s.find("VK",t);
		if(t != -1)
		{
			a[t]++;
			a[t+1]++;
			t+=2;
			cnt++;
		}
		else break;
	}
	for(int i = 0;i < len-1;i++)
	{
		if(a[i] == 0 && a[i+1] == 0 && (s[i] == 'V' || s[i+1] == 'K'))
		{
			cnt++;
			break;
		}
	}
	printf("%d",cnt);
	return 0;
}
