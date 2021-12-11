#include <bits/stdc++.h>
using namespace std;
char word[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};//??
int num[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
int main()
{
	int n = 0,a[10] = {0};
    string s;
    for(int i = 0;i < 6;i++)
    {
		cin >> s;
		for(int j = 0;j < 26;j++)
		{
			if(s == word[j] && num[j]%100)
				a[n++] = num[j]%100;
		}
	}
    sort(a,a+n);
    int first = 1;
    for(int i = 0;i < n;i++)
    {
    	if(first == 1 && a[i] < 10)
    	{
			first = 0;
		}
		else if(a[i] < 10)	cout << 0;
		printf("%d",a[i]);
	}
	if(first == 1)	cout << 0;
	return 0;
}
