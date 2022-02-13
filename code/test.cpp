#include <iostream>
using namespace std;
int main()
{
    FILE *fp;
    fp = fopen("1.txt","w");
    if(fp == NULL)  cout << "NULL";
    else cout << "exist";
    return 0;
}