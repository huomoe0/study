#include <iostream>
#include <set>
using namespace std;
const int maxn = 1000;
class Set
{
public:
    Set();
    int lower_bound(int x);
    void insert(int x);
    void erase(int x);
    bool empty();
    int size();
    void print();
    Set bing(const Set& s);
    Set jiao(const Set& s);
    Set cha(const Set& s);
private:
    int len;
    int data[maxn];
};

int main()
{
    Set sa, sb;
    int na, nb;
    int a[] = {4, 3, -1, 2, 3, 4, 5 , 1, 3, 5}, b[] = {2, 3, 5, 6, 4, 6, 3, 0, 7};
    na = sizeof(a)/sizeof(int), nb = sizeof(b)/sizeof(int);
    for(int i = 0;i < na;i++)  sa.insert(a[i]);
    for(int i = 0;i < nb;i++)  sb.insert(b[i]);
    sa.print();
    sb.print();
    Set s = sa.bing(sb);
    s.print();
    s = sa.jiao(sb);
    s.print();
    s = sa.cha(sb);
    s.print();
    
    return 0;
}

Set::Set()
{
    len = 0;
}
int Set::lower_bound(int x)
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
void Set::insert(int x)
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
void Set::erase(int x)
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
void Set::print()
{
    for(int i = 0;i < len;i++) cout << data[i] << " ";
    cout << "\n";
}
Set Set::bing(const Set& s)
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

Set Set::jiao(const Set& s)
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
Set Set::cha(const Set& s)
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