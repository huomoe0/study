#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y,money = 2000000000;
    cin >> n;
    for(int i = 0;i < 3;i++)
    {
        cin >> x >> y;
        int tmp = ceil(n*1.0/x)*y;
        if(tmp < money) money = tmp;
    }
    printf("%d",money);
    return 0;
}