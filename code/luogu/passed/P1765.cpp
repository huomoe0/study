#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int cnt = 0;
    for(int i = 0;i < s.size();i++)
    {
		switch(s[i])
		{
			case 'a':case 'd':case 'g':case 'j':case 'm':case 'p':case 't':case 'w':case ' ':
				cnt++;break;
			case 'b':case 'e':case 'h':case 'k':case 'n':case 'q':case 'u':case 'x':
				cnt += 2;break;
			case 'c':case 'f':case 'i':case 'l':case 'o':case 'r':case 'v':case 'y':
				cnt += 3;break;
			case 's':case 'z':
				cnt += 4;break;
		}
	}
	printf("%d",cnt);
	return 0;
}
