#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main()
{
    int c = getch();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf("%c\n",161);
    system("pause");
    return 0;
}