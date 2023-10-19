#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 1000;
class Set
{
public:
    friend ostream & operator<<(ostream &os, Set &s);
    friend istream & operator>>(istream &is, Set &s);
    Set() {len = 0; }
    int lower_bound(const int &x);
    void erase(const int &x);
    bool empty();
    int size();
    void operator()(const int &x);
    Set operator+(const Set& s);
    Set operator*(const Set& s);
    Set operator-(const Set& s);
private:
    int len;
    int data[maxn];
};
ostream & operator<<(ostream &os, Set &s)
{
    for(int i = 0;i < s.len;i++) os << s.data[i] << " ";
    os << "\n";
    return os;
}
istream & operator>>(istream &is, Set &s)
{
    string str;
    stringstream ss;
    int t;
    getline(is, str);
    ss << str;
    while(ss >> t)  s(t);
    return is;
}
int main()
{
    Set sa, sb;
    int na, nb;
    cout << "seta: ";
    cin >> sa;
    cout << "setb: ";
    cin >> sb;
    Set s = sa + sb;
    cout << "seta + setb: " << s;
    s = sa * sb;
    cout << "seta * setb: " << s;
    s = sa - sb;
    cout << "seta - setb: " << s;
    
    return 0;
}
int Set::lower_bound(const int &x)
{
    int l = 0, r = len-1;
    while(l < r)
    {
        int mid = l+r >> 1;
        if(data[mid] >= x)  r = mid;
        else l = mid + 1;
    }
    if(len && data[len-1] >= x) return l;
    return -1;
}
void Set::operator()(const int &x)
{
    int ind = lower_bound(x);
    if(ind == -1)   data[len++] = x;
    else if(data[ind] != x)
    {
        for(int i = len;i > ind;i--)  data[i] = data[i-1];
        data[ind] = x;
        len++;
    }
}
void Set::erase(const int &x)
{
    int ind = lower_bound(x);
    if(ind != -1 && data[ind] == x)
    {
        for(int i = ind+1;i < len;i++)    data[i-1] = data[i];
        len--;
    }
}
bool Set::empty()
{
    if(len == 0)    return true;
    return false;
}
int Set::size()
{
    return len;
}
Set Set::operator+(const Set& s)
{
    Set tmp;
    int i = 0, j = 0, cnt = 0;
    while(i < len && j < s.len)
    {
        if(data[i] < s.data[j]) tmp.data[cnt++] = data[i++];
        else if(data[i] > s.data[j])    tmp.data[cnt++] = s.data[j++];
        else j++;
    }
    while(i < len)  tmp.data[cnt++] = data[i++];
    while(j < s.len) tmp.data[cnt++] = s.data[j++];
    tmp.len = cnt;
    return tmp;
}

Set Set::operator*(const Set& s)
{
    Set tmp;
    int i = 0, j = 0, cnt = 0;
    while(i < len && j < s.len)
    {
        if(data[i] < s.data[j]) i++;
        else if(data[i] > s.data[j])    j++;
        else tmp.data[cnt++] = data[i], i++, j++;
    }
    tmp.len = cnt;
    return tmp;
}
Set Set::operator-(const Set& s)
{
    Set tmp;
    int i = 0, j = 0, cnt = 0;
    while(i < len && j < s.len)
    {
        while(s.data[j] < data[i])  j++;
        if(data[i] != s.data[j]) tmp.data[cnt++] = data[i++];
        else i++, j++;
    }
    while(i < len)  tmp.data[cnt++] = data[i++];
    tmp.len = cnt;
    return tmp;
}