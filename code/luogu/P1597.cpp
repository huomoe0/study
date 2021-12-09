#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3] = {0};
    char s1,s2;
    while(~scanf("%c:=%c;",&s1,&s2))
    {
		if(s2 >= '0' && s2 <= '9')	a[s1-'a'] = s2 - '0';
		else if(s2 >= 'a' && s2 <= 'c')	a[s1-'a'] = a[s2-'a'];
	}
	printf("%d %d %d",a[0],a[1],a[2]);
	return 0;
}
