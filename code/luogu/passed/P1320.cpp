#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt = 0;
    string line,s;
    cin >> line;
    do
    {
        s += line;
    }while(cin >> line);
    printf("%d ",line.size());
    if(s[0] == '1')
    {
        printf("0 ");
    }
    for(int i = 0;i < s.size();i++)
    {
        
        cnt++;
        if(s[i] != s[i+1])
        {
            printf("%d ",cnt);
            cnt = 0;
        }
    }
    return 0;
}