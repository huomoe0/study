#include <stdio.h>
#include <string.h>
int main()
{
    int a = 0,b = 0,len;
    char s[1100];
    scanf("%s",s);
    len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        if(s[i] == '(') a++;
        else if(s[i] == '[')    b++;
        else if(s[i] == ')')    a--;
        else    b--;
        if(a < 0 || b < 0)  break;
    }
    if(a == 0 && b == 0)    printf("YES\n");
    else    printf("NO\n");
    return 0;
}