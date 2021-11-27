#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a;
    scanf("%d",&n);
    set<int> s;
    set<int>::iterator p;
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a);
        s.insert(a);
    }
    printf("%d\n",s.size());
    for(p = s.begin();p != s.end();p++)
    {
        printf("%d ",*p);
    }
    return 0;
}