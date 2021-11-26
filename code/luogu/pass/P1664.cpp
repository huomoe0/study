#include <bits/stdc++.h>
int my_pow(int n)
{
    int i,result = 1;
    for(i = 0;i < n;i++)
    {
        result *= 2;
    }
    return result;
}
int main()
{
    int day = 0,n,i,count = 0,value = 0,flag,award;
    scanf("%d",&n);
    for(i = 1;i <= n;i++)
    {
        scanf("%d",&flag);
        if(flag)
        {
            if(count > 0)
            {
                day -= my_pow(count - 1);
                count = 0;
                if(day < 0)
                    day = 0;
            }
            day++;
            if(day < 3)
            award = 1;
        else if(day >= 3 && day < 7)
            award = 2;
        else if(day >= 7 && day < 30)
            award = 3;
        else if(day >= 30 && day < 120)
            award = 4;
        else if(day >= 120 && day < 365)
            award = 5;
        else
            award = 6;
            value += award;
            
        }
        else
            count++;
    }
    printf("%d\n",value);
    return 0;
}
