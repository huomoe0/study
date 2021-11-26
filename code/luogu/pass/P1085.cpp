#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,d = 0,sum = 0;
    for(int i = 1;i <= 7;i++)
    {
        cin >> x >> y;
        if(x + y > sum && x + y > 8)
        {
             d = i;
             sum = x+y;
        }
    }
    printf("%d",d);
    return 0;
}