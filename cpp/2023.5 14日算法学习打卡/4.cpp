#include <iostream>
#include <algorithm>
using namespace std;
const int N = 150010;
int a[N];
long long d[N];
int n, q, t;
bool check(int mid) //判断数量是否合法
{
    if(d[n] - d[n-mid] >= t)    return true;
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1;i <= n;i++)    scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        for(int i = 1;i <= n;i++)    d[i] = d[i-1] + a[i]; //前缀和，方便计算糖量
        while (q--)
        {
            int l = 1, r = n;
            scanf("%d", &t);
            if(t > d[n]) //大于全部糖之和
            {
                puts("-1");
                continue;
            }
            while (l < r) //二分糖的数量
            {
                int mid = l + r >> 1;
                if(check(mid))  r = mid;
                else l = mid+1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}