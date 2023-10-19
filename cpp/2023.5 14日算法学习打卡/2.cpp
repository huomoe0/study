#include <iostream>
using namespace std;
const int N = 110;
int a[N], d[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], d[i] = d[i-1]^a[i]; //求前缀和
    int res = 0;
    for(int i = 1;i <= n;i++) //枚举区间长度
        for(int j = 1;j <= n-i+1;j++)
            res = max(res, d[j-1] ^ d[j+i-1]); //记录长度为i的所有区间的最大值
    cout << res << "\n";
    return 0;
}