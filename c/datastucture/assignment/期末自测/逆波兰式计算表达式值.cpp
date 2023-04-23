#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	stack<int> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int t = 0;
			while (s[i] >= '0' && s[i] <= '9')
			{
				t = t * 10 + s[i] - '0';
				i++;
			}
			st.push(t);
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			int b = st.top(); st.pop();
			int a = st.top(); st.pop();
			switch (s[i])
			{
			case '+':st.push(a + b);break;
			case '-':st.push(a - b); break;
			case '*':st.push(a * b); break;
			case '/':st.push(a / b); break;
			}
		}
	}
	printf("%d", st.top());
	return 0;
}