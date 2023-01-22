#include <iostream>
#include <string>
using namespace std;
class card
{
public:
    void set(int v, char h) {value = v, huase = h;}
    void print()    {cout << value << " " << huase << "\n";}
private:
    int value;
    char huase;
};
class cardgame
{
public:
    void init();
    void display();
    void shuffle();
private:
    card a[54];
};
void cardgame::init()
{
    a[0].set(15, 0);
    a[1].set(14, 0);
    int cnt = 2;
    for(int i = 1;i <= 13;i++)
    {
        for(int j = 3;j <= 6;j++)
        {
            a[cnt++].set(i, j);
        }
    }
}
void cardgame::display()
{
    int cnt = 0;
    for(int i = 0;i < 54;i++)
    {
        
    }
}
int main()
{
    cardgame game;
    //cout << "\003\004\005\006";
    card a;
    a.print();
    return 0;
}