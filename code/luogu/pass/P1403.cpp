#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += n / i;
    }
    printf("%d", sum);
    return 0;
}

// #include <cstdio>     // ???
// int n, ans;
// int main()
// {
//     scanf("%d", &n);
//     for (int i = 1, j; i <= n; i = j + 1)
//     {
//         j = n / (n / i);
//         ans += (n / i) * (j - i + 1);
//     }
//     printf("%d", ans);
//     return 0;
// }