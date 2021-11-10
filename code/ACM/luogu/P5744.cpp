#include <bits/stdc++.h>
using namespace std;
struct stu
{
    string name;
    int age;
    int grade;
};
void train(stu* a)
{
    (*a).age += 1;
    (*a).grade *= 1.2;
    if((*a).grade > 600)
        (*a).grade = 600;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    stu a[10000];
    for(i = 0;i < n;i++)
    {
        cin >> a[i].name >> a[i].age >> a[i].grade;
        train(&a[i]);
        cout << a[i].name << ' ' << a[i].age << ' ' << a[i].grade << endl;
    }
    return 0;
}