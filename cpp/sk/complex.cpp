#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0) {real = r; imag = i; }
	Complex operator+(const Complex &c);
	Complex operator-(const Complex &c);
	bool operator==(const Complex &c);
	double operator!();
	Complex operator~();
	double get_real()const	{return real;}
	double get_imag()const	{return imag;}
	void display();

private:
	double real, imag;
};
Complex Complex::operator+(const Complex &c)
{
	Complex temp(real + c.real, imag + c.imag);
	return temp;
}
Complex Complex::operator-(const Complex &c)
{
	Complex temp(real - c.real, imag - c.imag);
	return temp;
}
Complex Complex::operator~()
{
	Complex temp(real, -imag);
	return temp;
}
bool Complex::operator==(const Complex &c)
{
	if(real == c.real && imag == c.imag)	return true;
	return false;
}
double Complex::operator!()
{
	return sqrt(imag*imag+real*real);
}
Complex operator*(const Complex &t, const Complex &u)
{

	return Complex(t.get_real() * u.get_real() - t.get_imag() * u.get_imag(),
				   t.get_imag() * u.get_real() + t.get_real() * u.get_imag());
}

Complex operator/(const Complex &t, const Complex &u)
{
	double abs_sq = u.get_real() * u.get_real() + u.get_imag() * u.get_imag();

	return Complex((t.get_real() * u.get_real() + t.get_imag() * u.get_imag()) / abs_sq,
				   (t.get_imag() * u.get_real() - t.get_real() * u.get_imag()) / abs_sq);
}
void Complex::display() 
{  
	string str;
    str = (imag < 0) ? "" : "+";
	cout << real << str << imag << "i" << endl; 
}
int main()
{
	Complex c1(7.7, 5.5), c2(4.2, -8.3), c3;
	c3 = c1 + c2;
	cout << "c1 + c2 = ";
	c3.display();
	c3 = c1 - c2;
	cout << "c1 - c2 = ";
	c3.display();
	c3 = c1 * c2;
	cout << "c1 * c2 = ";
	c3.display();
	c3 = c1 / c2;
	cout << "c1 / c2 = ";
	c3.display();
	c3 = ~c1;
	cout << "~c1 = ";
	c3.display();
	cout << "!c1 = " << !c1 << "\n";
	if(c1 == c2)	cout << "c1 == c2\n";
	else cout << "c1 != c2\n";
	return 0;
}