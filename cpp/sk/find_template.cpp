#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
template <typename T>
int find(T a[], int n, const T& x)
{
	for(int i = 0;i < n;i++)	if(a[i] == x)	return i;
	return -1;
}
int main()
{
	string a[20] = {"a", "b", "c", "d", "e"};
	string s  = "e";
	int t = find(a, 5, s);
	if(t != -1)	cout << t << endl;
	else cout << "can not find\n";
	return 0;
}