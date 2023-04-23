#include <iostream>
using namespace std;
#define MAXSIZE 100
template<class T>
struct SqList
{
	T* begin;
	int length;
	
	
	SqList()
	{
		this->begin = new T[MAXSIZE];
		this->length = 0;
	}
	SqList(int n)
	{
		this->begin = new T[n];
		this->length = 0;
	}
	SqList(SqList<T>& a)
	{
		if (this->begin != NULL)
		{
			delete this->begin;
			this->begin = NULL;
		}
		this->begin = new T[a.size()];
		for (int i = 0; i < a.size(); i++)
		{
			begin[i] = a[i];
		}
	}
	~SqList()
	{
		delete this->begin;
		if (this->begin != NULL)	this->begin = NULL;
	}

	T& operator[](int n)
	{
		return *(this->begin + n);
	}

	size_t size()
	{
		return length;
	}
	void clear()
	{
		length = 0;
	}

};

void test1()
{
	SqList<int> a;
	cout << a.size() << endl;

}
int main()
{

	test1();


	system("pause");
	return 0;
}