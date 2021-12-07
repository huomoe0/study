
#include <iostream>
using namespace std;
int s[1010][1010] = { 0 };
int main()
{
	int n, m, r, c, v;
	while (cin >> n >> m)
	{
		cin >> r >> c >> v;
		s[r][c] = v;
		int cnt = n * m;
		for (int i = m; i >= 1; i--)
		{
			for (int j = n; j >= 1; j--)
			{
				if (cnt == v)	cnt--;
					
				if(j != r || i != c)
					s[j][i] = cnt--;
			}
		}
		int flag = 1;
		for (int i = n; i >= 2; i--)
		{
			for (int j = m; j >= 2; j--)
			{
				if (s[i][j] < s[i - 1][j] || s[i][j] < s[i][j - 1])
				{

					flag = 0;
					break;
				}
			}
		}
		for (int i = n; i >= 2; i--)
		{
			if (s[i][1] < s[i - 1][1])
			{
				flag = 0;
				break;
			}
		}
		for (int i = m; i >= 2; i--)
		{
			if (s[1][i] < s[1][i-1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)	printf("No\n");
		else	printf("Yes\n");
	}
	return 0;
}