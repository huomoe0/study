#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int a[N];
int main()
{
    int len = 0;
    string s;
    cin >> s;
    for(int i = 0;i < s.length();i++)   if(s[i] >= '0' && s[i] <= '9')  a[len++] = s[i]-'0'; //从字符串中把数取出来
    sort(a, a+len); //排序
    for(int i = 0;i < len;i++)  cout << a[i] << "\n+"[i != len-1]; //按格式输出
    return 0;
}