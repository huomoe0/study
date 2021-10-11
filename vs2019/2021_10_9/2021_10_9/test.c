#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char ch;
    ch = getchar();
    while (ch != '\n')
    {
        switch (ch)
        {
            case 'A':ch = 'Z'; break;
            case 'B':ch = 'Y'; break;
            case 'C':ch = 'X'; break;
            case 'D':ch = 'W'; break;
            case 'E':ch = 'V'; break;
            case 'F':ch = 'U'; break;
            case 'G':ch = 'T'; break;
            case 'H':ch = 'S'; break;
            case 'I':ch = 'R'; break;
            case 'J':ch = 'Q'; break;
            case 'K':ch = 'P'; break;
            case 'L':ch = 'O'; break;
            case 'M':ch = 'N'; break;
            case 'N':ch = 'M'; break;
            case 'O':ch = 'L'; break;
            case 'P':ch = 'K'; break;
            case 'Q':ch = 'J'; break;
            case 'R':ch = 'I'; break;
            case 'S':ch = 'H'; break;
            case 'T':ch = 'G'; break;
            case 'U':ch = 'F'; break;
            case 'V':ch = 'E'; break;
            case 'W':ch = 'D'; break;
            case 'X':ch = 'C'; break;
            case 'Y':ch = 'B'; break;
            case 'Z':ch = 'A'; break;
        }
        putchar(ch);
        ch = getchar();
    }
}