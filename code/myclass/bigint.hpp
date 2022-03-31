#pragma once
#include <iostream>
#define MAXN 10000
class bigint
{
public:
	friend std::ostream& operator<<(std::ostream& ost, bigint a);
	friend bigint operator+(bigint& a, bigint& b);
	void flatten(int len)
	{
		for (int i = 1; i <= len; i++)
		{
			if (m_a[i] > 9)
			{
				m_a[i + 1] += 1;
				m_a[i] -= 10;
			}
		}
		while (!m_a[len])	len--;
		m_n = len;
	}
	/*bigint()
	{
		std::cout << "默认构造函数" << std::endl;
		m_n = 0;
		m_a = new int[MAXN];
		for (int i = 1; i < MAXN; i++)	m_a[i] = 0;
	}*/
	bigint(int n = 0)
	{
		//std::cout << "有参构造函数" << std::endl;
		m_n = 0;
		m_a = new int[MAXN];
		for (int i = 1; i < MAXN; i++)	m_a[i] = 0;
		while (n)
		{
			m_a[++m_n] = n % 10;
			n /= 10;
		}
	}

	bigint(const bigint& a)
	{
		//std::cout << "拷贝构造函数" << std::endl;
		m_n = a.m_n;
		m_a = new int[MAXN];
		for (int i = 1; i < MAXN; i++)	m_a[i] = 0;
		for (int i = 1; i <= m_n; i++)
			m_a[i] = a.m_a[i];
	}
	void operator=(const bigint& a)
	{
		m_n = a.m_n;
		for (int i = 1; i <= m_n; i++)
			m_a[i] = a.m_a[i];
	}

	~bigint()
	{
		if (m_a != NULL)
		{
			delete[]m_a;
			m_a = NULL;
		}
	}

	int& operator[](int n)
	{
		return m_a[n];
	}

private:
	int m_n; //数的长度
	int* m_a; //存放每一位
};


std::ostream& operator<<(std::ostream& ost, bigint a)
{
	for (int i = a.m_n; i >= 1; i--)
		ost << a[i];
	return ost;
}

bigint operator+(bigint& a, bigint& b)
{
	bigint c;
	int len = (a.m_n > b.m_n ? a.m_n : b.m_n);
	for (int i = 1; i <= len; i++)
		c[i] = a[i] + b[i];
	c.flatten(len + 1);
	return c;
}