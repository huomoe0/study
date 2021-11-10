#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000] = {0};
    int i,j,x;
    scanf("%d",&x);
    set<int> n;
    for(i = 0;i < x;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j = 0;j < x - 1;j++)
    {
        int tmp = abs(a[j+1] - a[j]);
        n.insert(tmp);
    }
    for(j = 1;j < x;j++)
    {
            if(!n.count(j))
            {
                printf("Not jolly\n");
                return 0;
            }
    }
    printf("Jolly\n");
    return 0;
}