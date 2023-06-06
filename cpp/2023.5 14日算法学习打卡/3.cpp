#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long l = 1, r = n*m;
    while (l < r)
    {
        long long mid = l + r >> 1, sum = 0;
        for(int i = 1;i <= n;i++)   sum += min(m, mid / i); //求有多少个数小于mid
        if(sum >= k)    r = mid;
        else l = mid+1;
    }
    cout << l << "\n";
    return 0;
}