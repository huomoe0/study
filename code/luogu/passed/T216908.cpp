#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1005] = {0},max = -200000,min = 2000000;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
		cin >> a[i];
		if(a[i] > max)	max = a[i];
		if(a[i] < min)	min = a[i];
	}
	for(int i = 0;i < n;i++)
    {
    	double w = 100*(a[i]-min)/(max-min);
		printf("%d ",(int)w);
	}
	return 0;
}
