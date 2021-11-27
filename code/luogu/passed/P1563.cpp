#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,m,a,s,j = 0,x;
    scanf("%d %d",&n,&m);
    vector<string> name(n);
    vector<int> fx(n);
    string b;
    for(i = 0;i < n;i++)
    {
        //cin >> x >> b;
        //name[i] = b;
        //fx[i] = x;
        cin >> fx[i] >> name[i];
    }
    for(i = 0;i < m;i++)
    {
        scanf("%d %d",&a,&s);
        if(a == fx[j])
        {
            j -= s;
        }
        else if(a != fx[j])
            j += s;
        if(j < 0)
            j += n;
        if(j >= n)
            j -= n;
    }
    cout << name[j];
    return 0;
}