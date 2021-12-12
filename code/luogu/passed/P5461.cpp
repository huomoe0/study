#include <bits/stdc++.h>
using namespace std;
int a[1040][1040];
void judge(int n,int x,int y)
{
	if(n == 0)
	{
		a[x][y] = 1;
		return;
	}
	//вСоб╫г
	judge(n-1,x + (1 << n-1),y);
	//сроб╫г
	judge(n-1,x + (1 << n-1),y + (1 << n-1));
	//срио╫г
	judge(n-1,x,y + (1 << n-1));
}
int main()
{
    int n;
    cin >> n;
    judge(n,1,1);
    for(int i = 1;i <= (1<<n);i++)
    {
		for(int j = 1;j <= (1<<n);j++)
    	{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
