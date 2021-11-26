#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    map<int,int> mp;
    map<int,int>::iterator it,it1;
    int n,i,id,len;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> id >> len;
        if(id == 1)
        {
            if(!mp[len])
            {
                mp[len]++;
            }
            else
            {
                cout << "Already Exist" << endl;
            }
        }
        else if(id == 2)
        {
            if(mp.empty())
            {
                cout << "Empty" << endl;
            }
            else if(mp[len] != 0)
            {
                cout << len << endl;
                mp.erase(len);
            }
            else //长度不存在
            {
                mp[len]++;
                it = mp.find(len);
                it1 = it;
                it++;
                if(it1 == mp.begin()) //没有比它短的
                {
                    cout << it->first << endl;
                    mp.erase(it);
                }
                else if(it == mp.end()) //没有比它长的
                {
                    cout << (--it1)->first << endl;
                    mp.erase(it1);
                }
                else if(len - (--it1)->first > it->first - len)
                {
                    cout << it->first << endl;
                    mp.erase(it);
                }
                else
                {
                    cout << it1->first << endl;
                    mp.erase(it1);
                }
                mp.erase(len);
            }
        }
    }
    return 0;
}