#include <bits/stdc++.h>
using namespace std;
int num(int n)
{
    int a = n;
    if(a == 0)
        return 6;
    int sum = 0;
    while(a > 0)
    {
        switch(a % 10)
        {
            case 0:sum += 6;break;
            case 1:sum += 2;break;
            case 2:sum += 5;break;
            case 3:sum += 5;break;
            case 4:sum += 4;break;
            case 5:sum += 5;break;
            case 6:sum += 6;break;
            case 7:sum += 3;break;
            case 8:sum += 7;break;
            case 9:sum += 6;break;
        }
        a /= 10;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(n < 13)// 1 + 1 = 2   13
    {
        printf("0");
        return 0;
    }

    int i,j,count = 0,max = 1;
    int a = (n-4) / 3;
    while(a > 0)
    {
        max = max * 10 + 1;
        a -= 2;
    }
    //cout << max;
    for(i = 0;i <= max;i++)
    {
        for(j = 0;j <= max;j++)
        {
            int c = i + j;
            if(num(i) + num(j) + num(c) == n-4)
            {
                //printf("%d + %d = %d\n",i,j,c);
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}