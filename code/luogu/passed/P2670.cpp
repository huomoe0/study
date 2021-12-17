#include <bits/stdc++.h>
using namespace std;
char s[105][105],ans[105][105];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
		for(int j = 1;j <= m;j++)
			scanf(" %c",&s[i][j]);
	}
	for(int i = 1;i <= n;i++)
    {
		for(int j = 1;j <= m;j++)
		{
			int cnt = 0;
			if(s[i][j] == '*')
			{
				ans[i][j] = '*';
			}
			else if(s[i][j] == '?')
			{
				if(s[i-1][j] == '*')	cnt++;
				if(s[i-1][j-1] == '*')	cnt++;
				if(s[i-1][j+1] == '*')	cnt++;
				if(s[i+1][j-1] == '*')	cnt++;
				if(s[i+1][j] == '*')	cnt++;
				if(s[i+1][j+1] == '*')	cnt++;
				if(s[i][j-1] == '*')	cnt++;
				if(s[i][j+1] == '*')	cnt++;
				ans[i][j] = cnt+'0';
			}
		}
	}
	for(int i = 1;i <= n;i++)
    {
		for(int j = 1;j <= m;j++)
		{
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
