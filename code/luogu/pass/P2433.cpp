#include <bits/stdc++.h>
using namespace std;
#define PIE 3.141593
int main()
{
    int T;
    cin >> T;
    if (T == 1)
    {
        cout << "I love Luogu!";
    }
    else if (T == 2)
    {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    }
    else if (T == 3)
    {
        int n = 14;
        printf("%d\n%d\n%d",n/4,4*(n/4),n-4*(n/4));
    }
    else if (T == 4)
    {
        double l = 500;
        cout << l/3;
    }
    else if (T == 5)
    {
        cout << (260+220)/(12+20);
    }
    else if (T == 6)
    {
        cout << sqrt(6*6+9*9);
    }
    else if (T == 7)
    {
        int n = 100;
        n += 10;
        cout << n << endl;
        n -= 20;
        cout << n << endl;
        cout << 0;
    }
    else if (T == 8)
    {
        int r = 5;
        double v = 4.0/3*PIE*r*r*r;
        cout << 2*r*PIE << endl;
        cout << PIE*r*r << endl;
        cout << v << endl;
    }
    else if (T == 9)
    {
        int n = 1;
        for(int i = 0;i < 3;i++)
        {
            n++;
            n *= 2;
        }
        cout << n;
    }
    else if (T == 10)
    {
        double v = (8.0*30-10*6) / 24;
        double init = 10.0*6 - v * 6;
        double ans = (init + 10 * v) / 10;
        cout << ans;
    }
    else if (T == 11)
    {
        double t = 100.0 / (8-5);
        cout << t;
    }
    else if (T == 12)
    {
        int a = 'M'-'A'+1;
        char ch = 'A'+17;
        cout << a << endl;
        cout << ch << endl;
    }
    else if (T == 13)
    {
        int r1 = 4,r2 = 10;
        double v = 4.0/3 * PIE*(r1*r1*r1 + r2*r2*r2);
        int r = cbrt(v);
        cout << r;
    }
    else if (T == 14)
    {
        for(int i=1;i<=110;i++)
        {
            int s=120-i;
            int ans=s*i;
            if(ans==3500) 
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}