#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b)   swap(a,b);
    if(a > c)   swap(a,c);
    if(b > c)   swap(b,c);
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("Not triangle");
    }
    else
    {
        if(c*c == a*a + b*b)
            printf("Right triangle\n");
        else if(a*a + b*b > c*c)
            printf("Acute triangle\n");
        else if(a*a + b*b < c*c)
            printf("Obtuse triangle\n");
        if (a == b || b == c || a == c)
            printf("Isosceles triangle\n");
        if (a == b && b == c)
            printf("Equilateral triangle\n");
    }
    return 0;
}