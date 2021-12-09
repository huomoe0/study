#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    double a[105] = {0};
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
    	int max = 0,min = 100;
		for(int j = 0;j < m;j++)
		{
			int t;
			cin >> t;
			a[i] += t;
			if(min > t)	min = t;
			if(max < t)	max = t;
		}
		a[i] -= (min+max);
		a[i] /= (m-2);
	}
	sort(a,a+n);
	printf("%.2f",a[n-1]);
	return 0;
}
