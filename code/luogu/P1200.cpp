#include <bits/stdc++.h>
using namespace std;
int main()
{
    string hx,dw;
    cin >> hx >> dw;
    int hxn = 1,dwn = 1;
    for(int i = 0;i < (int)hx.size();i++)
    {
		hxn *= (hx[i]-'A'+1);
	}
	for(int i = 0;i < (int)dw.size();i++)
    {
		dwn *= (dw[i]-'A'+1);
	}
	if(hxn % 47 == dwn % 47)
		printf("GO");
	else	printf("STAY");
	return 0;
}
