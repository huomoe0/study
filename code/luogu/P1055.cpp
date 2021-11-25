#include <bits/stdc++.h>
using namespace std;
int main()
{
	string isbn;
    cin >> isbn;
    int i = 1,sum = 0;
    for(int j = 0;j < 12;j++)
    {
        if(isbn[j] <= '9' && isbn[j] >= '0')
        {
            sum += (isbn[j]-48) * i;
            i++;
        }
    }
    char ch = isbn[12];
    if((sum%11 == 10 && ch == 'X') || sum%11 == (ch-48))
    {
        cout << "Right";
    }
    else
    {
        if(sum%11 == 10)    isbn[12] = 'X';
        else    isbn[12] = sum%11+48;
        cout << isbn;
    }
    return 0;
}