#include <cstdio>
void Swap(int &a) //C++引用
{
    a = 0;
}
int main()
{
    int a = 10;
    Swap(a);
    printf("%+d",a);
    return 0;
}