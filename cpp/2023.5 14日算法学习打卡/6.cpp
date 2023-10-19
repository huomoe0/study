#include <iostream>
#include <algorithm>
const int N = 100010;
int a[N];
int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 0;i < n;i++) std::cin >> a[i];
    std::sort(a, a+n); // 排序
    int res = 0, sum = 0;
    for(int i = n-1;i >= 0;i--) // 每次选择容量最大的，则U盘数量最少
    {
        sum += a[i];
        res++;
        if(sum >= m)    break;
    }
    std::cout << res << "\n";
    return 0;
}