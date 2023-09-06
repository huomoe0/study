#include <iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);

        int i = 0, j = 3*n+1, cnt = 0;

        while (i < j) //要使不存在子序列BAN只需把所有的N都移到A前即可
        {
             do ++i; while (i % 3 != 2);
             do --j; while (j % 3 != 0);
             if(i < j)
             {
                cnt++;

             }
        }
        printf("%d\n", cnt);
        i = 0, j = 3*n+1;
        while (i < j)
        {
             do ++i; while (i % 3 != 2);
             do --j; while (j % 3 != 0);
             if(i < j)
             {
                printf("%d %d\n", i, j);
             }
        }
    }
    return 0;
}
