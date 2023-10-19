#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define int long long
const int mod = 1e9+7;
struct node
{
    int id, e; //变量号 幂
};
struct xiang
{
    int xs; //系数
    vector<node> v; //各个变量
};
bool operator==(xiang &a, xiang &b)
{
    if(a.v.size() != b.v.size())    return false;
    int n = a.v.size();
    for(int i = 0;i < n;i++)
        if(a.v[i].id != b.v[i].id || a.v[i].e != b.v[i].e)  return false;
    return true;
}
vector<xiang> add(vector<xiang> &a, vector<xiang> &b, int sign)
{
    for(int i = 0;i < b.size();i++)
    {
        int isfind = 0;
        if(sign)    b[i].xs = -b[i].xs;
        for(int j = 0;j < a.size();j++)
            if(b[i] == a[j])
            {
                isfind = 1;
                a[j].xs += b[i].xs;
                break;
            }
        if(!isfind) a.push_back(b[i]);
    }
    return a;
}
vector<xiang> mul(vector<xiang> &a, vector<xiang> &b)
{
    vector<xiang> ans;
    for(xiang x : a)
        for(xiang y : b)
        {
            int i = 0, j = 0;
            xiang c;
            c.xs = x.xs * y.xs;
            for(;i < x.v.size();i++)
            {
                while (j < y.v.size() && y.v[j].id < x.v[i].id) c.v.push_back(y.v[j]), j++;
                if(j < y.v.size() && y.v[j].id == x.v[i].id) c.v.push_back({x.v[i].id, y.v[j].e + x.v[i].e}), j++;
                else c.v.push_back({x.v[i].id, x.v[i].e});
            }
            while (j < y.v.size()) c.v.push_back(y.v[j]), j++;
            ans.push_back(c);
        }
    return ans;
}
void print(vector<xiang> &exp)
{
    if(exp.size() == 1 && exp[0].v.size() == 1)
    {
        cout << exp[0].xs << endl;
        return;
    }
    if(exp.size() == 0) cout << 0;
    for(int i = 0;i < exp.size();i++)
    {   
        if(i && exp[i].xs > 0) cout << "+";
        if(abs(exp[i].xs) != 1) cout << exp[i].xs;
        if(exp[i].xs == -1) cout << "-";
        for(node k : exp[i].v)
        {
            if(k.e > 1)    cout << "x" << k.id << "^" << k.e;
            else if(k.e == 1)   cout << "x" << k.id;
        }
    }
    cout << endl;
}
vector<xiang> qiudao(vector<xiang> a, int dst)
{
    vector<xiang> ans;
    for(xiang i : a)
    {
        int isfind = 0;
        for (int j = 0;j < i.v.size();j++)
        {
            if(i.v[j].id == dst)
            {
                isfind = 1;
                i.xs *= i.v[j].e--;
                break;
            }
        }
        if(!isfind || i.xs == 0)    continue;
        isfind = 0;
        for(int j = 0;j < ans.size();j++)
            if(i == ans[j])
            {
                 ans[j].xs += i.xs;
                 isfind = 1;
                 break;
            }
        if(!isfind) ans.push_back(i);
    }
    return ans;
}
int solve(vector<xiang> &a, vector<int> &v)
{
    int ans = 0;
    for(xiang i : a)
    {
        int t = 1;
        for(int j = 0;j < i.v.size();j++)
        {
            int tmp = 1;
            for(int k = 1;k <= i.v[j].e;k++)    t *= v[i.v[j].id];
        }
        t = t * i.xs % mod;
        ans = (ans + t) % mod;
    }
    return ans;
}
signed main()
{
    int n, m;
    string s;
    cin >> n >> m;
    getchar();
    getline(cin, s);
    stringstream ss;
    ss << s;

    stack<vector<xiang>> stk; //表达式

    while (ss >> s)
    {
        if(s[0] == 'x')
        {
            int t = 0;
            for(int i = 1;i < s.size();i++) t = t * 10 + s[i] - '0';
            node newnode = {t, 1};
            xiang newxiang = {1, {newnode}};
            vector<xiang> exp = {newxiang};
            stk.push(exp);
        }
        else if(s[0] == '-' && s.size() > 1 || s[0] >= '0' && s[0] <= '9')
        {
            int t = 0;
            for(int i = s[0] == '-';i < s.size();i++)   t = t * 10 + s[i] - '0';
            if(s[0] == '-') t = -t;
            node newnode = {1, 0};
            xiang newxiang = {t, {newnode}};
            vector<xiang> exp = {newxiang};
            stk.push(exp);
        }
        else
        {
            vector<xiang> s2 = stk.top(); stk.pop();
            vector<xiang> s1 = stk.top(); stk.pop();
            vector<xiang> newxiang;
            if(s == "+")    newxiang = add(s1, s2, 0);
            else if(s == "-")   newxiang = add(s1, s2, 1);
            else newxiang = mul(s1, s2);
            stk.push(newxiang);
        }
    }

    vector<xiang> exp = stk.top();
    //print(exp);
    while (m--)
    {
        int dst;
        vector<int> v(n+1);
        cin >> dst;
        for(int i = 1;i <= n;i++)   cin >> v[i];
        vector<xiang> dao = qiudao(exp, dst);
        //print(dao);
        cout << (solve(dao, v)%mod + mod) % mod << endl;
    }
    return 0;
}