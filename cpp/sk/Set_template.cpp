#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 1000;
template<typename T> class Set;
template<typename T>
ostream& operator<<(ostream& os, Set<T>& s)
{
    for (int i = 0; i < s.len; i++) os << s.data[i] << " ";
    os << "\n";
    return os;
}
template<typename T>
istream& operator>>(istream& is, Set<T>& s)
{
    string str;
    stringstream ss;
    T t;
    getline(is, str);
    ss << str;
    while (ss >> t)  s.insert(t);
    return is;
}
template<typename T>
class Set
{
public:
    friend ostream& operator<< <>(ostream& os, Set<T>& s);
    friend istream& operator>> <> (istream& is, Set<T>& s);
    Set() { len = 0; }
    int lower_bound(const T& x);
    int size() { return len; }
    void insert(const T& x);
    Set operator+(const Set& s);
    Set operator-(const Set& s);
private:
    int len;
    T data[maxn];
};

template<typename T>
int Set<T>::lower_bound(const T& x)
{
    int l = 0, r = len - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (data[mid] >= x)  r = mid;
        else l = mid + 1;
    }
    if (len && data[len - 1] >= x) return l;
    return -1;
}
template<typename T>
void Set<T>::insert(const T& x)
{
    int ind = lower_bound(x);
    if (ind == -1)   data[len++] = x;
    else if (data[ind] != x)
    {
        for (int i = len; i > ind; i--)  data[i] = data[i - 1];
        data[ind] = x;
        len++;
    }
}
template<typename T>
Set<T> Set<T>::operator+(const Set<T>& s)
{
    Set<T> tmp;
    int i = 0, j = 0, cnt = 0;
    while (i < len && j < s.len)
    {
        if (data[i] < s.data[j]) tmp.data[cnt++] = data[i++];
        else if (data[i] > s.data[j])    tmp.data[cnt++] = s.data[j++];
        else j++;
    }
    while (i < len)  tmp.data[cnt++] = data[i++];
    while (j < s.len) tmp.data[cnt++] = s.data[j++];
    tmp.len = cnt;
    return tmp;
}
template<typename T>
Set<T> Set<T>::operator-(const Set<T>& s)
{
    Set<T> tmp;
    int i = 0, j = 0, cnt = 0;
    while (i < len && j < s.len)
    {
        while (s.data[j] < data[i])  j++;
        if (data[i] != s.data[j]) tmp.data[cnt++] = data[i++];
        else i++, j++;
    }
    while (i < len)  tmp.data[cnt++] = data[i++];
    tmp.len = cnt;
    return tmp;
}

int main()
{
    Set<double> sa, sb;
    cout << "seta: ";
    cin >> sa;
    cout << "setb: ";
    cin >> sb;
    Set<double> s = sa + sb;

    cout << "seta + setb: " << s;
    s = sa - sb;
    cout << "seta - setb: " << s;

    return 0;
}