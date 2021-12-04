//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int a[10] = {1,2,3,4,5,6,7,8,9};
//    int n;
//    cin >> n;
//    do
//    {
//		for(int i = 0;i < n;i++)
//		{
//			printf("%5d",a[i]);
//		}
//		printf("\n");
//	}while(next_permutation(a,a+n));
//}


#include <bits/stdc++.h>
using namespace std;
int a[15],flag[15];
void print(int n)
{
	for(int i = 1;i <= n;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
}
void dfs(int dep,int n)
{
	if(dep > n)
	{
		print(n);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!flag[i])
		{
			flag[i] = 1;
			a[dep] = i;
			dfs(dep+1,n);
			flag[i] = 0;
		}
	}
}
int main()
{
    int n;
    cin >> n;
    dfs(1,n);
    return 0;
}
