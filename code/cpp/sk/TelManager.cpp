#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Mytel
{
    friend class TelManager;
private:
    string name, tel;
};
class TelManager
{
public:

    TelManager() { count = 0; }
    void load();
    void add(string& name, string& tel);
    void del(const string& t);
    void alter(int ind, string& name, string& tel);
    int find(const string& t);
    void print();
    void save();
private:
    Mytel a[1000];
    int count;
};

int main()
{
    TelManager tm;
    string name, tel;
    int sel;
    while (1)
    {
        cout << "***************电话薄管理系统***************";
        cout << endl << endl;
        cout << "1:加载数据      2:输出数据      3:按姓名查询" << endl
            << "4:添加数据      5:保存数据      6:删除数据    0:退出"  << endl;
        cout << "********************************************";
        cout << "\n请选择(0-6)";
        cin >> sel;
        switch (sel)
        {
        case 1:tm.load(); break;
        case 2:tm.print(); break;
        case 3:cin >> name; tm.find(name); break;
        case 4:cin >> name >> tel; tm.add(name, tel); break;
        case 5:tm.save(); break;
        case 0:exit(1);
        }
    }
    return 0;
}

void TelManager::load()
{
    fstream fs;
    fs.open("data.txt", ios::in);
    if (!fs.is_open())
    {
        ofstream ofs("data.txt");
        ofs.close();
    }
    string name, tel;
    while (fs >> name >> tel)
    {
        a[++count].name = name, a[count].tel = tel;
    }
}
void TelManager::add(string& name, string& tel)
{
    a[++count].name = name, a[count].tel = tel;
}
void TelManager::del(const string& t)
{
    int ind = find(t);
    if (ind == -1) return;
    for (int i = ind; i < count; i++)  a[i] = a[i + 1];
    count--;
}
void TelManager::alter(int ind, string& name, string& tel)
{
    if (ind > count || ind < 1) return;
    a[ind].name = name, a[ind].tel = tel;
}
int TelManager::find(const string& t)
{
    for (int i = 1; i <= count; i++)   if (a[i].name == t)   return i;
    return -1;
}
void TelManager::print()
{
    cout << "id\tname\ttel\n";
    for (int i = 1; i <= count; i++)
        cout << i << "\t" << a[i].name << "\t" << a[i].tel << endl;
}
void TelManager::save()
{
    fstream fs("data.txt", ios::out);
    for (int i = 1; i <= count; i++)   fs << a[i].name << " " << a[i].tel << "\n";
}