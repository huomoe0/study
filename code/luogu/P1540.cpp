#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,count = 0,i,j;
    scanf("%d %d",&n,&m);
    vector<int> s;
    vector<int> word;
    for(i = 0;i < m;i++)
    {
        int tmp;
        cin >> tmp;
        word.push_back(tmp);
    }
    int flag = 0;
    i = 0;
    while(!word.empty())
    {
        for(j = 0;j < s.size();j++)
        {
            if(word[i] == s[j])
                flag = 1;
        }
        if(flag)
        {
            word.erase(word.begin());
            flag = 0;
        }
        else
        {
            if(s.size() == n)
                s.erase(s.begin());
            s.push_back(word[i]);
            count++;
        }
    }
    cout << count;
    return 0;
}