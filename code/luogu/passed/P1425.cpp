#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h1,h2,m1,m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int a = (h2-h1)*60 + m2-m1;
    printf("%d %d",a/60,a%60);
    return 0;
}