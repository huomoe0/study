#include <iostream>
using namespace std;
const double pi = 3.14159;
class Circle
{
public:
    void set(double r)
    {
        m_r = r;
    }
    double area()
    {
        return pi * m_r * m_r;
    }
private:
    double m_r;
};
int main()
{
    Circle c;
    double r;
    cin >> r;
    c.set(r);
    cout << c.area() << "\n";
    return 0;
}