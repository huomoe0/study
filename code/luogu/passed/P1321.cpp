#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[300] = {0};
    scanf("%s",s);
    int cnt1 = 0,cnt2 = 0,len = strlen(s);
    for(int i = 0;i < len;i++)
    {
		if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y')
			cnt1++;
		if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l')
			cnt2++;
	}
	printf("%d\n%d",cnt1,cnt2);
	return 0;
}
