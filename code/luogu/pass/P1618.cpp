#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,count = 0,x,y,z;
    int s[] = {1,2,3,4,5,6,7,8,9};
    cin >> a >> b >> c;
    do
    {
        x = s[0] * 100 + s[1]*10+s[2];
        y = s[3]*100+s[4]*10+s[5];
        z = s[6]*100+s[7]*10+s[8];
        if(y*1.0/x == b*1.0/a && z*1.0/x == c*1.0/a && z*1.0/y == c*1.0/b)
        {
            printf("%d %d %d\n",x,y,z);
            count++;
        }
    } while (next_permutation(s,s+9));
    if(count == 0)
    printf("No!!!");
    return 0;
}