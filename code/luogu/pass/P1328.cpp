#include <bits/stdc++.h>
using namespace std;
int game(int a,int b)
{
    switch(a)
    {
        case 0:
            if(b == 2 || b == 3)
                return 0;
            else if(b == 1 || b == 4)
                return 1;
            else 
                return 2;
        case 1:
            if(b == 0 || b == 3)
                return 0;
            else if(b == 4 || b == 2)
                return 1;
            else 
                return 2;
        case 2:
            if(b == 1 || b == 4)
                return 0;
            else if(b == 0 || b == 3)
                return 1;
            else
                return 2;
        case 3:
            if(b == 2 || b == 4)
                return 0;
            else if(b == 0 || b == 1)
                return 1;
            else return 2;
        case 4:
            if(b == 1 || b == 0)
                return 0;
            else if(b == 2 || b == 3)
                return 1;
            else return 2;
        default:return 2;
    }
}
int main()
{
    int n,a,b,i,j,tmp,count1 = 0,count2 = 0;
    scanf("%d %d %d",&n,&a,&b);
    vector<int> na;
    vector<int> nb;
    for(i = 0;i < a;i++)
    {
        scanf("%d",&tmp);
        na.push_back(tmp);
    }
    for(i = 0;i < b;i++)
    {
        scanf("%d",&tmp);
        nb.push_back(tmp);
    }
    int x = 0,y = 0,t;
    for(i = 0;i < n;i++)
    {
        t = game(na[count1],nb[count2]);
        if(t == 0)//a win
        {
            x++;
        }
        else if(t == 1)//b win
        {
            y++;
        }
        count1++;
        count2++;
        if(count1 == a)
            count1 = 0;
        if(count2 == b)
            count2 = 0;
    }
    printf("%d %d",x,y);
}