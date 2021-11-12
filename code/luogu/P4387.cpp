#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,q,count = 0;
    stack<int> s;
    cin >> n;
    
    for(i = 0;i < n;i++)
    {
        cin >> q;
        int a[q+1],b[q+1];
        for(j = 0;j < q;j++)
            cin >> a[j];
        for(j = 0;j < q;j++)
            cin >> b[j];

        for(j = 0;j < q;j++)
        {
            s.push(a[j]);
            while(s.top() == b[count])
            {
                s.pop();
                count++;
                if(s.empty())
                    break;
            }
        }
        if(s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        while(!s.empty())
            s.pop();
        count = 0;
    }
    return 0;
}