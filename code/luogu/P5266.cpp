#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    map<string,int> mp;
    int n,score,i,id;
    string name;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> id;
        if(id == 1)
        {
            cin >> name >> score;
            mp[name] = score;
            cout << "OK" << endl;
        }
        else if(id == 2)
        {
            cin >> name;
            if(mp.find(name) != mp.end())
            {
                cout << mp[name] << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if(id == 3)
        {
            cin >> name;
            if(mp.find(name) != mp.end())
            {
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if(id == 4)
        {
            cout << mp.size() << endl;
        }
    }
    return 0;
}