#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    string name;
    int p;
    map<string, int> shop;
    while (cin >> n)
    {
        shop.clear();
        for (int i = 0; i < n; i++)
            cin >> name;
        cin >> m;
        while (m--)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> p >> name;
                shop[name] += p;
            }
            int rank = 1;
            map<string, int>::iterator it;
            for (it = shop.begin(); it != shop.end(); it++)
            {
                if (it->second > shop["memory"])
                    rank++;
            }
            cout << rank << endl;
        }
    }
    return 0;
}
