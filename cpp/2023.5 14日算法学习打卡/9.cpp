#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        set<int> s;
        for(int i = 0;i < n;i++)
        {
            int t;
            scanf("%d", &t);
            s.insert(t);
        }
        printf("%d\n", s.size());
    }
    return 0;
}