#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 1,y = 1,n,flag = 0;
    cin >> n;
    for(int i = 1;i < n;i++)
    {
		if(flag == 0)
		{
			x--;
			y++;
		}
		else if(flag == 1)
		{
			x++;
			y--;
		}
		if(x == 0 && y > 0)
		{
			x++;
			flag = 1;
		}
		else if(y == 0 && x > 0)
		{
			y++;
			flag = 0;
		}
	}
	printf("%d/%d",x,y);
	return 0;
}
