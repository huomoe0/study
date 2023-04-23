#include <iostream>
#include <string>
using namespace std;
class Figure
{
protected:
    double radius;
public:
    virtual double area() {return 0; }
    virtual double volume() {return 0; }
    Figure() {radius = 0;}
    Figure(double f) {radius = f;}
    void setvalue(double v) {radius = v; }
};
class Sphere : public Figure // circle
{
public:
    Sphere(double f) : Figure(f) {}
    double area() {return 4*3.14*radius*radius; }
    double volume() {return 4.0/3.0*3.14*radius*radius*radius; }
};
class Column : public Figure //yuanzhu
{
public:
    double area() {return 2*3.14*radius*radius + 2*3.14*radius*height; }
    double volume() {return 3.14*radius*radius*height; }
    Column(double f, double h) : Figure(f) {height = h; }
    void setvalue(double v, double h) {radius = v; height = h; }
private:
    double height;
};
double area(Figure &a)
{
    return a.area();
}
double volume(Figure *a)
{
    return (*a).volume();
}
int main()
{
    Figure a(1);
    Sphere b(1);
    Column c(1, 1);
    cout << "Figure area " << area(a) << endl;
    cout << "Sphere area " <<  area(b) << endl;
    cout << "Column area " <<  area(c) << endl;
    cout << "Figure volume " <<  volume(&a) << endl;
    cout << "Sphere volume " <<  volume(&b) << endl;
    cout << "Column volume " <<  volume(&c) << endl;
    return 0;
}