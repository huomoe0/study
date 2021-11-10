#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int n = 0;
    char ch;
    cin >> ch;
    while(ch != '@' && n >= 0)
    {
        if(ch == '(')
            n++;
        else if(ch == ')')
            n--;
            cin >> ch;
    }
    if(n == 0)
        printf("YES");
    else printf("NO");
    return 0;
}