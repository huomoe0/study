#include <iostream>
using namespace std;
long long ans = 0;
void h(int n, char a, char b, char c)
{
	if (n == 1)
	{
		cout << a << " -> " << c << "\n";
		ans++;
		return;
	}
	h(n - 1, a, c, b);
	cout << a << " -> " << c << "\n";
	ans++;
	h(n - 1, b, a, c);
}
int main()
{
	int n;
	cin >> n;
	h(n,'A', 'B', 'C');
	cout << ans << "\n";
	return 0;
}