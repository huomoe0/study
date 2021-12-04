#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,a,b;
    cin >> s;
    int ind;
    if((ind = s.find('%')) != -1)
    {
    	s.erase(ind,1);
		 int len = (int)s.size();
		 for(int i = 0;i < len/2;i++)
		 {
		 	char t = s[i];
		 	s[i] = s[len-i-1];
		 	s[len-i-1] = t;
		 }
		 s += '%';
		 while(s[0] == '0')	s.erase(0,1);
		 //cout << s;
	}
	else if((ind = s.find('.')) != -1)
	{
		a = s.substr(0,ind);
		b = s.substr(ind+1,s.size()-a.size()-1);
		int lena = (int)a.size();
		int lenb = (int)b.size();
		for(int i = 0;i < lena/2;i++)
		 {
		 	char t = s[i];
		 	a[i] = a[lena-i-1];
		 	a[lena-i-1] = t;
		 }
		 for(int i = 0;i < lenb/2;i++)
 		 {
 		 	char t = b[i];
 		 	b[i] = b[lenb-i-1];
 		 	b[lenb-i-1] = t;
 		 }
 		 while(a[0] == '0')	a.erase(0,1);
 		 while(b[0] == '0')	b.erase(0,1);
		cout << a << endl << b;
	}
	
}
