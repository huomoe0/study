#include <iostream>
#include <string>
using namespace std;
class Teacher
{
public:
	Teacher() { level = time = base = 0; }
	~Teacher() {}
	virtual void salary() = 0;
protected:
	int level, time, base;
	string zhicheng, name;
};
class jiaoshou : public Teacher
{
public:
	jiaoshou()
	{
		cout << "���������� �ȼ�  ��ʱ: ";
		string name;
		int l, t;
		cin >> name >> l >> t;
		if (l == 1) base = 8000;
		else if (l == 2)base = 7500;
		level = l, time = t, this->name = name;
		zhicheng = "����";
	}
	void salary()
	{
		cout << name << "�Ĺ���Ϊ:" << base + time * 50 << "\n";
	}
};
class fujiaoshou : public Teacher
{
public:
	fujiaoshou()
	{
		cout << "���������� �ȼ� ��ʱ: ";
		string name ;
		int l, t;
		cin >> name >> l >> t;
		if (l == 1) base = 7000;
		else if (l == 2)base = 6000;
		else if (l == 3)base = 5000;
		level = l, time = t, this->name = name;
		zhicheng = "������";
	}
		
	void salary()
	{
		cout << name << "�Ĺ���Ϊ:" << base + time * 30 << "\n";
	}
		
};
class jiangshi : public Teacher
{
public:
	jiangshi()
	{
		cout << "���������� ��ʱ: ";
		string name ;
		int t;
		cin >> name >> t;
		base = 4500;
		time = t, this->name = name;
		zhicheng = "��ʦ";
	}
		
	void salary()
	{
		cout << name << "�Ĺ���Ϊ:"<< base + time * 20 <<"\n";
	}
		
};

void f(Teacher& p)
{
	p.salary();
}

int main()
{
	jiaoshou a;
	fujiaoshou b;
	jiangshi c;
	f(a);
	f(b);
	f(c);
	return 0;
}

