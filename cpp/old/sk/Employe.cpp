#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
class Employe
{
public:
    Employe() {no = maxno++; name = ""; wage = 0; }
    Employe(string name, double wage) {no = maxno++; this->name = name, this->wage = wage; }
    void info() {cout << "no: " << no << "\t" << "name: " << name << "\t" << "wage: " << wage; }
private:
    int no;
    string name;
    double wage;
    static int maxno;
};
int Employe::maxno = 1000;
int main()
{
    int n;
    fstream fs;
    string name;
    double wage;
    fs.open("empdata.dat", ios::out);
    cout << "employe number: ";
    cin >> n;
    
    for(int i = 0;i < n;i++)
    {
        
        cout << "name wage: ";
        cin >> name >> wage;
        fs << name << " " << wage << "\n";
    }
    fs.close();
    fs.open("empdata.dat", ios::in);
    if(!fs.is_open())
    {
        cout << "error\n";
        return -1;
    }
    while(fs >> name >> wage)
    {
        Employe t(name, wage);
        t.info();
        cout << "\n";
    }
    
    return 0;
}