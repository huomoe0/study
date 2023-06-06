#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200010;
vector<int> a;
bool flag[N];
int n, K;
int main()
{
    scanf("%d%d", &n, &K);
    for(int i = 0;i < n;i++)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    for(int i = 1, j = 0;i < n;i++)
    {
        while (j < i && (a[j] + K < a[i] || a[j] > a[i]))    j++; //跳过不满足条件的，如果a[j]和a[i]相等，在后面可能被吞噬，所以不跳过
        while (j < i && a[j] + K >= a[i] && a[j] < a[i])   flag[j++] = 1; //如果满足条件，就把对应的细菌吞噬
    }
    int res = 0;
    for(int i = 0;i < n;i++) if(!flag[i])   res++; //统计没被吞噬的细菌数量
    printf("%d\n", res);
    return 0;
}