#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long sum = 0;
    int n,cnt = 0;
    while(cin >> n)
    {
		sum += n;
		cnt++;
	}
	sum *= (1 << cnt-1);
	printf("%lld",sum);
	return 0;
}
