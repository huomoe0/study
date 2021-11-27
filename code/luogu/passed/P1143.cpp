#include <bits/stdc++.h>
using namespace std;
int n,m,bns[100];
long long ans;
char num[100];
int main()
{
    scanf("%d",&n);
    scanf("%s",num);
    scanf("%d",&m);
    int len=strlen(num);
    for(int i=0;i<len;i++)
    {
        if(num[i]>='A'&&num[i]<='F')
            ans+=(num[i]-'A'+10)*pow(n,len-i-1);
        else if(num[i]>='0'&&num[i]<='9')
            ans+=(num[i]-'0')*pow(n,len-i-1);
    }
    len=0;
    while(ans)
    {
        bns[len++]=ans%m;
        ans/=m;
    }
    for(int i=len -1;i>=0;i--)
        if(bns[i]>=10)
            cout<<char(bns[i]+55);
        else
            cout<<bns[i];
    return 0;
}