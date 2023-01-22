#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    int no;
    string name;
    float score;
    Student(string name, float score)
    {
        no = maxno++, count++, this->name = name, this->score = score, total += score;
    }
    ~Student()
    {
        count--, total -= score;
        if (!count)
            total = 0;
    }
    static float sum()
    {
        return total;
    }
    static float average()
    {
        if (count)
            return total / count;
        else
            return 0;
    }
private:
    static int count;
    static float total;
    static int maxno;
};
int Student::count = 0;
float Student::total = 0;
int Student::maxno = 1000;

int main()
{
    Student a("a", 90);
    Student b("b", 91);
    Student c("c", 60);
    Student d("d", 87);
    cout << Student ::sum() << "\n";
    cout << Student ::average() << "\n";
    return 0;
}
