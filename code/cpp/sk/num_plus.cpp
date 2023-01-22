#include <iostream>
#include <assert.h>
using namespace std;
int gcd(int x, int y)
{
    int r = x % y;
    while(r)
    {
        x = y, y = r, r = x % y;
    }
    return y;
}
class Rn
{
    friend ostream& operator<<(ostream &os, const Rn& a);
public:
    Rn(int a = 0, int b = 1);
    void set(int a, int b);
    void reduce(int &x, int &y);
    Rn operator+(const Rn&a);
    Rn operator-(const Rn&a);
    Rn operator*(const Rn&a);
    Rn operator/(const Rn&a);
    bool operator==(const Rn&a);
private:
    int m_a, m_b;
};
int main()
{
    Rn a(-2, 3), b(4, 5);
    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "a / b = " << a / b << "\n";
    if(a == b)  cout << "a == b\n";
    else cout << "a != b\n";
    return 0;
}
Rn::Rn(int a, int b)
{
    assert(b);
    m_a = a, m_b = b;
}
void Rn::set(int a, int b)
{
    assert(b);
    if(b < 0)   b = -b, a = -a;
    reduce(a, b);
    m_a = a, m_b = b;
}
void Rn::reduce(int &x, int &y)
{
    int flag = 0;
    if(x < 0)   x = -x, flag = 1;
    int g = gcd(x, y);
    x /= g, y /= g;
    if(flag)    x = -x;
}
ostream & operator<<(ostream &os, const Rn& a)
{
    os << a.m_a << "/" << a.m_b;
    return os;
}
Rn Rn::operator+(const Rn&a)
{
    int x = m_a * a.m_b + m_b * a.m_a, y = m_b * a.m_b, flag = 0;
    reduce(x, y);
    return (Rn){x, y};
}
Rn Rn::operator-(const Rn&a)
{
    int x = m_a * a.m_b - m_b * a.m_a, y = m_b * a.m_b, flag = 0;
    reduce(x, y);
    return (Rn){x, y};
}
Rn Rn::operator*(const Rn&a)
{
    int x = m_a * a.m_a, y = m_b * a.m_b, flag = 0;
    reduce(x, y);
    return (Rn){x, y};
}
Rn Rn::operator/(const Rn&a)
{
    int x = m_a * a.m_b, y = m_b * a.m_a, flag = 0;
    if(y < 0)   x = -x, y = -y;
    reduce(x, y);
    return (Rn){x, y};
}
bool Rn::operator==(const Rn&a)
{
    if(a.m_a == m_a && a.m_b == m_b)    return true;
    return false;
}