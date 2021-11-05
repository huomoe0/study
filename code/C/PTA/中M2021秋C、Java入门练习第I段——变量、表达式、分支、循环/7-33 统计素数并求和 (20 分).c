#include <stdio.h>
int main()
{
    int m = 0;
    int n = 0;
    scanf("%d %d",&m,&n);
    int i = 0;
    int count = 0;
    int sum = 0;
    for(i = m;i <= n;i++)
    {
        int a = 0;
        for(a = 2;a < i;a++)
        {
            if(i == 2)
            {
                count++;
            }
            else if(i > 2)
            {

                if(i % a == 0)
                {
                    break;
                }
                else
                {
                    count++;
                   sum += i;
                   printf("%d",i);
                }
            }
        }
    }
    return 0;
}