#include <bits/stdc++.h>
using namespace std;
int main()
{
	int y,m,d = 0;
    cin >> y >> m;
    switch(m)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            d = 31;break;
        case 4:case 6:case 11:case 9:
            d = 30;break;
        case 2:
        if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
            d = 29;
        else d = 28;
        break;
    }
    printf("%d",d);
    return 0;
}