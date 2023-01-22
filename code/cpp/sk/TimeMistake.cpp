#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class TimeMistake
{
public:
    TimeMistake() {}
    TimeMistake(const string &s) {message = s;}
    string what() {return message;}
private:
    string message;
};
string time24to12(string s)
{
    if(s.size() < 4 || s.size() > 5)    throw TimeMistake("error1");
    if(s.size() == 4) s = '0' + s;
    for(int i = 0;i < 5;i++)
    {
         if((i != 2 && (s[i] > '9' || s[i] < '0'))
          || (i == 2 && s[i] != ':'))   throw TimeMistake("error1");
    }
    int h = 0, m = 0;
    for(int i = 0;i < 2;i++)    h = h*10 + s[i] - '0';
    for(int i = 3;i < 5;i++)    m = m*10 + s[i] - '0';
    if(h < 0 || h >= 24 || m < 0 || m >= 60)    throw TimeMistake("error2");
    h %= 12;
    string res;
    for(int i = 1;i >= 0;i--)    res =  char(m%10 + '0') + res , m /= 10;
    res = ':' + res;
    if(!h)  res = "0" + res;
    while(h)    res = char(h%10 + '0') + res, h /= 10;
    return res;
}
void handle(string s)
{
    try
    {
        string t = time24to12(s);
        cout << t << endl;
    }
    catch(TimeMistake e)
    {
        cerr << e.what() << '\n';
    }
}
int main()
{
    string s;
    cin >> s;
    handle(s);
    cout << "end\n";
    return 0;
}