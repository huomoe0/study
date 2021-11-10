#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int a[1010][1010];

int main()
{
    //freopen("in.txt","r",stdin);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int i = 1, j = 1, num = 0;
    while(num <= n * m)
    {
        a[i][j] = ++num;
        int dpi = i, dpj = j;
        if(i == x && j == y)break;

        if((i + j) % 2 == 0)i--,j++;
        else i++,j--;

        if(i > n || i < 1)i = dpi,j = dpj,j++;
        if(j > m || j < 1)i = dpi,j = dpj,i++;
    }
    cout << a[x][y];
    return 0;
}
