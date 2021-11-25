#include <bits/stdc++.h>
using namespace std;
int main()
{
    int min,max,i,t,j;
    scanf("%d %d",&min,&max);
    if(min % 2 == 0)    min++;
    for(i = min;i <= max;i+=2)
    {
        t = i;
        int cnt = 0;
        int tmp = 0;
        while(t > 0)
        {
            tmp = tmp * 10 + t % 10;
            cnt++;
            t /= 10;
        }
         //除11外偶数位回文数不是素数
        if(i == tmp)
        {
            for(j = 2;j <= sqrt(i);j++)
            {
                if(i % j == 0)  break;
            }
            if(j > sqrt(i)) printf("%d\n",i);
        }

    }
    return 0;
}