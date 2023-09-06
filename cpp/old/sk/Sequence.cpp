#include <iostream>
#include <string>
using namespace std;
class Sequence
{
public:
    void init();
    void append(string);
    void del(string);
    void output();
private:
    int last;
    string s[100];
};
void Sequence::init()
{
    last = 0;
}
void Sequence::append(string s)
{
     this->s[this->last++] = s;
}
void Sequence::del(string s)
{
    int i = 0;
    while(i < this->last && this->s[i] != s)    i++;
    if(i < this->last)
    {
        for(int j = i+1;j < this->last;j++) this->s[j-1] = this->s[j];
        this->last--;
    }
}
void Sequence::output()
{
    for(int i = 0;i < this->last;i++)   cout << this->s[i] << "\n";
}
int main()
{
    Sequence a;
    string s;
    a.init();
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> s;
        a.append(s);
    }
    a.output();
    while(m--)
    {
        cin >> s;
        a.del(s);
    }
    a.output();
    return 0;
}