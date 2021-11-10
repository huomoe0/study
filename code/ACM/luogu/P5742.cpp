#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int id;
    int a;
    int b;
};
void ex(stu a)
{
    double zh = a.a * 0.7 + a.b * 0.3;
    if(zh >= 80 && a.a + a.b > 140)
        printf("Excellent\n");
    else printf("Not excellent\n");
}
int main()
{
    int n,i;
    cin >> n;
    stu a[1000];
    for(i = 0;i < n;i++)
    {
        cin >> a[i].id >> a[i].a >> a[i].b;
        ex(a[i]);
    }
    return 0;
}