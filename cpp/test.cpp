#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 100010;
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    

    for(int i : v)  cout << i << " ";
    cout << "\n";
    vector<int> s = {48, 5};
    auto t = search(v.begin(), v.end(), s.begin(), s.end());
    cout << t - v.begin() << endl;
    cout << search_n(v.begin(), v.end(), 2, 3) - v.begin() << endl;
    return 0;
}