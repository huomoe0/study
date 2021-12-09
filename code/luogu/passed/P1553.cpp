#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,a,b;
    cin >> s;
    int ind;
    if((ind = s.find('%')) != -1) //百分数
    {
    	s.erase(ind,1);
		 int len = (int)s.size();
		 for(int i = 0;i < len/2;i++)
		 {
		 	char t = s[i];
		 	s[i] = s[len-i-1];
		 	s[len-i-1] = t;
		 }
		 
		 if(s.size() != 1)  
		 	while(s[0] == '0')	s.erase(0,1);
		 	s += '%';
		 cout << s;
	}
	else if((ind = s.find('.')) != -1 || (ind = s.find('/')) != -1) // 小数 分数
	{
		a = s.substr(0,ind);
		b = s.substr(ind+1,s.size()-a.size()-1);
		char sign = s[ind];
		int lena = (int)a.size();
		int lenb = (int)b.size();
		for(int i = 0;i < lena/2;i++)
		 {
		 	char t = s[i];
		 	a[i] = a[lena-i-1];
		 	a[lena-i-1] = t;
		 }
		 if(a.size() != 1 && a[0] == '0') //分子前面的零
		 	while(a[0] == '0')	a.erase(0,1);
		 
		 for(int i = 0;i < lenb/2;i++)
  		 {
  		 	char t = b[i];
  		 	b[i] = b[lenb-i-1];
  		 	b[lenb-i-1] = t;
  		 }
		 if(b.size() != 1 && b[0] == '0') //分母前面的零
		 {
	  		 while(b[0] == '0')	b.erase(0,1);
		 }
 		 if(sign == '.')//清除小数后面的零
 		 {
		  	while(b[b.size()-1] == '0' && b.size() != 1)	b.erase(b.size()-1,1);
		  }
		cout << a << sign << b;
	}
	else //整数
	{
		reverse(s.begin(),s.end());
		if(s.size() != 1)
			while(s[0] == '0')	s.erase(0,1);
		cout << s;
	}
	return 0;
}
