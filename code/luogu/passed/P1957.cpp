#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c;
    scanf("%d\n",&n);
    char s[100],ans[100] = {0},ch;
    for(int i = 0;i < n;i++)
    {
        fgets(s,sizeof(s),stdin);
        if(s[0] == 'a' || s[0] == 'b' || s[0] == 'c')
            ch = s[0],s[0] = ' ';
        sscanf(s," %d %d",&a,&b);
        switch(ch)
        {
            case 'a': c = a+b;sprintf(ans,"%d+%d=%d",a,b,c);break;
            case 'b': c = a-b;sprintf(ans,"%d-%d=%d",a,b,c);break;
            case 'c': c = a*b;sprintf(ans,"%d*%d=%d",a,b,c);break;
        }
        printf("%s\n%d\n",ans,strlen(ans));
    }
    return 0;
}