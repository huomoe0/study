#include <iostream>
#pragma pack(4)
using namespace std;
class person
{
public:
    int m_a;
    string a;//aaaas
    int m_b;
    person(int a,int b):m_a(a),m_b(b)
    {
        //cout << "moren" << endl;
    }
    static void print()
    {
        cout << c << endl;
    }
    static int c;
};
void test1(person *p)
{
    cout << p->a << endl;
}
int main()
{
    //person p(10,100);
    //test1(&p);
    cout << "1";
    return 0;
}