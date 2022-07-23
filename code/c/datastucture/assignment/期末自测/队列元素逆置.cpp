#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	queue<int> q;
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	for (int i = 0; i < n; i++)
	{
		s.push(q.front());
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		q.push(s.top());
		cout << s.top() << " ";
		s.pop();
	}
	return 0;

}