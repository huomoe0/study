#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
using namespace std;
class Date
{
protected:
    int year, month, day;
public:
    void print()
    {
        cout << setfill('0') << setw(2) << month << "-" << setw(2) << day << "-" << setw(4) << year << "\n";
    }
    void setdate(int y, int m, int d)  {year = y, month = m, day = d;}
    Date(int y, int m, int d)  {year = y, month = m, day = d;}
    Date()
    {
        time_t now = time(NULL);
        tm* tm_t = localtime(&now);
        year = tm_t->tm_year + 1900;
        month = tm_t->tm_mon + 1;
        day = tm_t->tm_mday;
    }
};
class ShortE : public Date
{
public:
    void print()
    {
        cout << setfill('0') << setw(2) << day << "-" << setw(2) << month << "-" << setw(4) << year << "\n";
    }
    ShortE(int y, int m, int d):Date(y, m, d) {}
    ShortE() {}
};
class MediumDate : public Date
{
public:
    void print()
    {
        const char *s[] = {"","Jan.", "Feb.", "Mar.", "Apr.", "May.", "Jun.", "Jul.", "Aug.", "Sept.", "Oct.", "Nov.", "Dec."};
        cout << setfill('0') << s[month] << setw(2) << day << "," << setw(4) << year << "\n";
    }
    MediumDate(int y, int m, int d):Date(y, m, d) {}
    MediumDate() {}
};
class LongDate : public Date
{
public:
    void print()
    {
        const char*s[] = {"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cout << setfill('0') << s[month] << " " << setw(2) << day << ", " << setw(4) << year << "\n";
    }
    LongDate(int y, int m, int d):Date(y, m, d) {}
    LongDate() {}
};

int main()
{
    Date a;
    ShortE b;
    MediumDate c;
    LongDate d(2018, 4, 14);
    a.print();
    b.print();
    c.print();
    d.print();
    return 0;
}