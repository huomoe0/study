#include <bits/stdc++.h>
using namespace std;
int Ceil(const double a)
{
    if((int)a == a) return a;
    else return (int)(a+1);
}
int main()
{
    string dest,s;
    cin >> dest >> s;
    int i = 0;
    for(i = 0;i < dest.size()-s.size();i++)
    {
		for(int j = i;j < s.size();j++)
		{
			if(dest[j] != s[j])	break;
		}
	}
	printf("%d",i);
    
    return 0;
}
