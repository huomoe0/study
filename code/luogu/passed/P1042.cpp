#include <bits/stdc++.h>
using namespace std;
char s[70000];
int cnt;
void score(int n)
{
	int a = 0,b = 0;
	for(int i = 0;i < cnt;i++)
	{
		if(s[i] == 'W')	a++;
		else if(s[i] == 'L')	b++;
		
		if((a >= n || b >= n) && abs(a-b)>=2)
    	{
			printf("%d:%d\n",a,b);
			a = 0;
			b = 0;
		}
	}
	printf("%d:%d\n",a,b);
	return;
}
int main()
{
    char ch;
    while(cin >> ch && ch != 'E')
    {
    	if(ch == 'W' || ch == 'L')
			s[cnt++] = ch;
	}
	score(11);
	cout << '\n';
	score(21);
	return 0;
}
